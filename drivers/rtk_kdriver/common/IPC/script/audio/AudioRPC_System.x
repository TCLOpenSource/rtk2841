
.insert <RPCBaseDS.h>
.insert <AudioRPCBaseDS.h>

/**
 *	What is a flow?
 *	If several pins are dependent, it should be the same flow.
 *	Otherwise, they are indepent flows.
 *
 **/

/**
 *	The flow of set focus
 *
 *	Set focus is an issue between two flows.
 *
 *	Firstly, only 1 flow (simple playback) is running, normally it is in (audio) master mode.
 *
 *	When the second flow is created, it should be set in the skip mode. System should explicitly
 *	indicate it. It means the even audio decoder has data in its ring buffer, it is still not in the
 *	master mode. The data will be read from the input buffer if it is accumulated to a complete process-able
 *	frame, but the data is read out and parsed.
 *
 *	Due to the variable size property of WMA and AAC, the skip must be implemented as a parsing mode.
 *  For the decoder's output side, the output of the decoder will give null pointer after parsing.
 *
 *	Now we have two flows. one is audio master, the other is video master (audio in skip mode).
 *	The former is the default in focus process.
 *
 *	If user want to set focus on the background flow. The system commands includes:
 *
 *	F means the init foreground flow, B means the init background flow. They switches roles after the
 *	process of set focus is done.
 *
 *		(1)	Mixer is F only.													<-- previous state
 *		(2)	Set decoder F to skip mode.											<-- RPC
 *		(3)	F's output is null pointer, it will be interpreted to zeros by PP.	<-- auto
 *		(4)	PP fades out the zeros.												<-- auto
 *			PP could have a mutex to check (5) is done after (4) is done.
 *		(5)	Set mixer to be B only.												<-- general RPC call
 *		(6)	Set decoder B to slave mode.										<-- RPC
 *		(7)	After a while, decoder B become in master mode.						<-- System update mastership
 *		(8) Set focus is done, the roles of F and B are switched.
 *
 *	Since the mixer of set focus flow works as a selector, it is not need to mix anything.
 *	For DV mixer or general PP mixer, it should be in-band commands.
 *
 **/

/**
 *	The flow of switch agent
 *
 *	Switch agent is inside a single flows.
 *
 *	There are two ways to do so:
 *
 *	(1)	A single decoder agent with two decoder instances
 *	(2)	Two independent flows at the same time
 *
 *	The later one is not preferred. It sends to the mixers.
 *	The former one needs a smooth filter to remove peaks during the connection range of two decoders.This could be done in in-band command.
 *
 **/

/**
 *		The differences between pause and stop
 *
 *		<< Pause >>
 *
 *		Pause is the transition state between running and stop.
 *		Pause accumulates data for the purpose that we can run the flow quickly.
 *
 *		Basically, pause command is used to pause encoder or decoder.
 *		To speed up the process,
 *			we puase AO to pause decoder and pause AI to pause encoder.
 *
 *	 	For an encoder flow (starts with AI), AI will be the only one module which is really paused.
 *		For a decoder flow (ends with AO), AO will be the only one module is really paused.
 *			So encoder/decoder will ignore pause.
 *
 *		When AO is pause, the data will be jammed from the downstream to the upstream.
 *			Therefore the decoder is paused. The register AIO_IO_pause will be set.
 *			No data will be sent out.
 *
 *		When AI is pause, the data will be drained out from upstream to downstream.
 *			Therefore the encoder is paused. The register AIO_IO_pause will be set.
 *
 *		To increase the responsible speed, the pause for AI and AO is implemented by a function call. It means
 *		even AI and AO is not scheduled, the pause function could be executed firstly.
 *
 *		[Special Cases]
 *
 *		If file to file transcoding is invloved as an DMA server, Decoder will have a fan out to AO.
 *			When the AO fan out is jammed, the Decoder will be jammed and paused.
 *
 *		Some special flows will have direct connection from AI to AO.
 *		There are two cases found so far:
 *		(1) Karaoke Microphone or Encoder with Echo out while recording.
 *		(2) SPDIF Pass trough or decoding.
 *
 *		If pause is issued under the two cases, the buffer between AI and AO will be stuffed with out-of-date
 *		data.
 *
 *		In (1), encoder will still go on. AI and AO is paused. When resume,
 *			flush the buffer between AI and AO first. But it is not recommended.
 *			We had better not accept pause while recording.
 *			If we want to pause encoder, we should user PauseEncoder RPC.
 *		In (2), Pause is OK even AI and AO are both paused. Since we will have a decoder
 *			(even LPCM decoder) within the flow.
 *
 *		<< Mute >>
 *
 *		We will always mute AO only.
 *
 *		When AI is muted, it will send null pointer to the downstream ring buffer, and it will be interpreted
 *		to zeros finally. However, it is not recommended to do so.
 *
 *		When AO is muted, it will set register AIO_O_dac_ctrl. Zeros will be sent out.
 *
 *		When decoder/encoder receives "mute", it will ignore "mute".
 *
 *		If we want the encoder to encoder zeros, we should use MuteEncoder RPC call.
 *		When encoder receives "MuteEncoder", the mixer before encoder will send zero to the encoder.
 *
 *		[Special Cases]
 *
 *		If file to file transcoding is invloved as an DMA server, Decoder will have a fan out to AO.
 *			When the AO fan out is muted, the Decoder will still go on.
 *
 *
 *		<< Stop >>
 *
 *		When AI is stopped, AI will disbale ADC.
 *		When AO is stopped, AO will disable DAC.
 *
 *		When Encoder/Decoder is stopped, it is freezed.
 *
 **/

/**
 *	set focus, step, audio is in slave mode.
 **/

program AUDIO_SYSTEM {
  version VERSION {



/**
 *	The Audio high level API is defined as below.
 * 	Basically the order of appearance is the same as the video API for easier reference.
 *
 *	The original version is written by Taro. After discussing with Yuan-Tao, Song, Chen and Y.C.,
 *	the adapted version is written by Cash. This the version concluded on 2005/10/25.
 *
 *
 **/

/** Common API --------------------------------------------------------------------------------------
 *
 *	The Common APIs that all audio filter should support them.
 * 	Currently, APIs are defined as below.
 *
 *	RPCRES_LONG	AUDIO_RPC_ToAgent_Create(AUDIO_RPC_INSTANCE)=1;
 *	HRESULT     AUDIO_RPC_ToAgent_Connect(RPC_CONNECTION x) = 2;
 *	HRESULT     AUDIO_RPC_ToAgent_InitRingBuffer(RPC_RINGBUFFER x) = 3;
 *	HRESULT     AUDIO_RPC_ToAgent_Run(AUDIO_RPC_SEND_LONG x) = 4;	<-- RUN 才看 command
 *	HRESULT     AUDIO_RPC_ToAgent_Pause(AUDIO_RPC_SEND_LONG x) = 5;
 *	HRESULT     AUDIO_RPC_ToAgent_Stop(AUDIO_RPC_SEND_LONG x) = 6;
 *	HRESULT     AUDIO_RPC_ToAgent_Destroy(AUDIO_RPC_SEND_LONG x) = 7;
 *	HRESULT     AUDIO_RPC_ToAgent_Flush(AUDIO_RPC_SEND_LONG x) = 8;
 *	HRESULT 	AUDIO_RPC_ToAgent_SetRefClock(AUDIO_RPC_SET_REFCLOCK x) = 9 ;
 * 	RPCRES_LONG	AUDIO_RPC_ToAgent_GetStatus(AUDIO_RPC_SEND_LONG x)= 10;
 *	HRESULT		AUDIO_RPC_ToAgent_SetSeeking(AUDIO_RPC_SEEK)=11;*
 *
 *	HRESULT		AUDIO_RPC_ToAgent_SetSpeed(AUDIO_RPC_SET_SPEED)= 102;	<-- RPC 的順序不重要
 *
 *----------------------------------------------------------------------------------------------------
 **/
/**
 *	\fn	RPCRES_LONG AUDIO_RPC_ToAgent_Create(AUDIO_MODULE_TYPE x)
 *  \brief	To create an audio filter in audio cpu side.
 *
 *	This function creates a audio filter in audio cpu side. And it will
 *	return the struct RPCRES_LONG which contains a pointer to the created
 *  filter to system software. The System software will specify the filter
 *  type which it requires. Only 4 types of AUDIO_RPC_INSTANCE are supported,
 * 	i.e. AUDIO_DECODER, AUDIO_ENCODER, AUDIO_AI, and AUDIO_OUT.
 *
 *	Encoder/decoder are set to be UNKNOWN mode first. Then init RPC call will set a default value.
 *	New Format will be given in in-band command.
 *
 *  \param  a struct named AUDIO_MODULE_TYPE.
 *
 **/

  RPCRES_LONG AUDIO_RPC_ToAgent_Create(AUDIO_RPC_INSTANCE) = 1;

/**
 *	\fn	HRESULT     AUDIO_RPC_ToAgent_Connect(RPC_CONNECTION x)
 *  \brief To connect two audio filters.
 *
 *  This function connects two filters, for example an audio decoder filter
 *  and an audio out filter could be connected to make a playback flow.
 *
 *  \param  a struct named RPC_CONNECTION.
 *  \return	an instance ID.
 *
 **/

  HRESULT		AUDIO_RPC_ToAgent_Connect(AUDIO_RPC_CONNECTION)=2;

/**
 *	\fn	  HRESULT     AUDIO_RPC_ToAgent_InitRingBuffer(RPC_RINGBUFFER x)
 *  \breif	To Init the Ring Buffer.
 *
 *  This function initializes the ring buffer setting.
 *  System software invokes this function to inform audio filter the setting of
 *  an available ring buffer.
 *
 *  \param  struct RPC_RINGBUFFER.
 *
 **/

    HRESULT		AUDIO_RPC_ToAgent_InitRingBufferHeader(AUDIO_RPC_RINGBUFFER_HEADER)=3;

/**
 *	\fn	HRESULT     AUDIO_RPC_ToAgent_Run(AUDIO_RPC_SEND_LONG x)
 *  \breif	Let an audio filter run.
 *
 *  This function commands the audio filter to run. For AO, all the registers must be set before "run"
 *	is sent by system side. When AO gets "run", it set the go bit to enable the DAC.
 *
 *  \param  instance ID.
 *
 */

  /*HRESULT     AUDIO_RPC_ToAgent_Run(AUDIO_RPC_SEND_LONG x) = 4;*/
   HRESULT		AUDIO_RPC_ToAgent_Run(long)=4;

/**
 *	\fn	HRESULT     AUDIO_RPC_ToAgent_Pause(AUDIO_RPC_SEND_LONG x)
 *  \breif	Let an audio filter pause.
 *
 *  This function commands audio filter enter pause status.
 *
 *	AI/AO will be paused by receiving a pause command.
 *	encoder will ignore pause because it listen to PauseEncoder only.
 *	mixer will be paused,
 *
 *  \return
 *  \param  instance ID.
 */

 /* HRESULT     AUDIO_RPC_ToAgent_Pause(AUDIO_RPC_SEND_LONG x) = 5;*/
   HRESULT		AUDIO_RPC_ToAgent_Pause(long)=5;

/**
 *	\fn	HRESULT     AUDIO_RPC_ToAgent_Stop(AUDIO_RPC_SEND_LONG x)
 *  \breif	To stop an audio filter
 *
 *  This function stops the operation of an audio filter.
 *
 *  \return
 *  \param	instance ID;
 */

  /*HRESULT     AUDIO_RPC_ToAgent_Stop(AUDIO_RPC_SEND_LONG x) = 6; */
    HRESULT		AUDIO_RPC_ToAgent_Stop(long)=6;

/**
 *	\fn	HRESULT     AUDIO_RPC_ToAgent_Destroy(AUDIO_RPC_SEND_LONG x)
 *  \brief To destroy an audio filter.
 *
 *  This function forces to kill all tasks of the audio filter.
 *
 *  \return
 *  \param	instance ID;
 */

  /*HRESULT     AUDIO_RPC_ToAgent_Destroy(AUDIO_RPC_SEND_LONG x) = 7;*/
  HRESULT		AUDIO_RPC_ToAgent_Destroy(long)=7;

/**
 *	\fn	HRESULT     AUDIO_RPC_ToAgent_Flush(AUDIO_RPC_SEND_LONG x);
 *  \brief To flush the stalling data in input queues of components in an audio filter.
 *  This function inform each component to flush stalling data and eventually
 *  clean up all the queuing data in pins.
 *
 *  \return
 *  \param	instance ID;
 */

  /*HRESULT     AUDIO_RPC_ToAgent_Flush(AUDIO_RPC_SEND_LONG x) = 8;*/
  HRESULT		AUDIO_RPC_ToAgent_Flush(AUDIO_RPC_SENDIO)=8;
/**
 *	\fn	HRESULT 	AUDIO_RPC_ToAgent_SetRefClock(AUDIO_RPC_SET_REFCLOCK x)
 *	\brief	Send a pointer the the address of reference clock
 *
 *  A pointer is sent to the audio middleware so it will know where the reference clock data is.
 *	Basically only the AI and AO will response to this function.
 *
 *	\return
 *	\param	struct AUDIO_RPC_SET_REFCLOCK
 */

  /*	HRESULT 	AUDIO_RPC_ToAgent_SetRefClock(AUDIO_RPC_SET_REFCLOCK x) = 9 ; */

	HRESULT		AUDIO_RPC_ToAgent_SetRefClock(AUDIO_RPC_REFCLOCK)=9;


/**
 *	\fn	RPCRES_LONG	AUDIO_RPC_ToAgent_GetStatus(AUDIO_RPC_SEND_LONG)
 *	\brief	To check out the status
 *
 *	It is basically for debugging purpose, the status of the assigned instance ID would be reported.
 *
 *	enum	AUDIO_COMMAND
 *	{
 *		START,			// no wait state, because audio signal might come before the video signal. slent audio would not get too much trouble.
 *		PAUSE,			// no VOBU consideration
 *		STOP,			// no VOBU consideration
 *		RUN,			// ready to go
 *		INIT			// replace the init function
  *	};
 *
 *	\return	Status.
 *	\param	instance ID.
 */

  	RPCRES_LONG	AUDIO_RPC_ToAgent_GetStatus(AUDIO_RPC_SEND_LONG x)= 10;

  	HRESULT		AUDIO_RPC_ToAgent_SetSeeking(AUDIO_RPC_SEEK)=11;

    HRESULT		AUDIO_RPC_ToAgent_DisConnect(AUDIO_RPC_CONNECTION)=12;

	AUDIO_RPC_FORMAT_INFO		AUDIO_RPC_ToAgent_BitstreamValidation(AUDIO_RPC_DEC_BITSTREAM_BUFFER) = 15;

	int		AUDIO_RPC_AO_ToAgent_IsFinishPlaySoundEvent(int) = 17;
/**
 *	\fn	HRESULT		AUDIO_RPC_ToAgent_AudioConfig( AUDIO_CONFIG_COMMAND)
 *	\brief	Configures audio general variables
 *	\param	Audio config command ( please look into the AudioRPCBaseDS.x for more details)
 *
 *	\return	Returns fail or success.
 */
	HRESULT		AUDIO_RPC_ToAgent_AudioConfig( AUDIO_CONFIG_COMMAND) = 16;


 /** Decoder API --------------------------------------------------------------------------------------
 *
 *	The Decoder API is designed for decoder filters.
 *
 *	HRESULT		AUDIO_RPC_DEC_ToAgent_Init(AUDIO_RPC_DEC_INIT x) = 12 ;
 *	HRESULT		AUDIO_RPC_DEC_ToAgent_SkipMode(AUDIO_RPC_SEND_LONG x) = 203;
 *	HRESULT		AUDIO_RPC_DEC_ToAgent_SetSpeed(AUDIO_RPC_SET_SPEED x) = 204;
 *
 *----------------------------------------------------------------------------------------------------
 **/

/**
 * \fn	HRESULT			AUDIO_RPC_DEC_ToAgent_Init(AUDIO_RPC_DEC_INIT);
 * \brief This function init the all setting decoder needs.
 * \return
 * \param  A struct AUDIO_RPC_DEC_INIT.
 */

  	HRESULT		AUDIO_RPC_DEC_ToAgent_Init(AUDIO_RPC_DEC_INIT x) = 31 ;

/**
 * \fn	HRESULT		AUDIO_RPC_DEC_ToAgent_SkipMode(AUDIO_RPC_SEND_LONG x)
 * \brief 		Set decoder to Skip mode = parsing mode.
 * \return
 * \param  instance ID.
 */

    HRESULT     AUDIO_RPC_DEC_ToAgent_SkipMode(AUDIO_RPC_SEND_LONG x) = 32;

    HRESULT     AUDIO_RPC_DEC_ToAgent_SetDualMonoOutMode(AUDIO_RPC_CHANNEL_OUT_MODE) = 33;
    AUDIO_RPC_GET_PTS_INFO         AUDIO_RPC_DEC_ToAgent_GetPTS(long instanceID) = 34;

/**
 *	\fn HRESULT		AUDIO_RPC_DEC_ToAgent_SetSpeed(AUDIO_RPC_SET_SPEED x);
 *	\brief	To set the speed of playback.
 *
 *	Note that it takes two filters to make smoothplay works.
 *
 *	The first function is issued to audio decoder and then to audio out.
 *	It is because we have to produce more data first, then the smooth playback module could performace
 * 	fast forward. The data amount in the input ring buffer could just be normal for slow playback.
 *
 *	\param	struct AUDIO_RPC_SET_SPEED.
 *
 */

 /* now use   HRESULT		AUDIO_RPC_ToAgent_SetSeeking(AUDIO_RPC_SEEK)=6;  instead */

   /*	HRESULT		AUDIO_RPC_DEC_ToAgent_SetSpeed(AUDIO_RPC_SET_SPEED x)= 204; */

/** Encoder API -------------------------------------------------------------------------------------
 *
 *	The Encoder API is designed for Encoder filters.
 *
 *	HRESULT		AUDIO_RPC_ENC_ToAgent_Init(AUDIO_RPC_ENC_INIT)= 13;
 *	HRESULT     	AUDIO_RPC_ENC_ToAgent_SetBitRate(AUDIO_RPC_ENC_SET_BITRATE x) = 16;
 *	HRESULT		AUDIO_RPC_ENC_ToAgent_StartEncoder(AUDIO_RPC_SEND_LONG x) = 26;
 *  	HRESULT		AUDIO_RPC_ENC_ToAgent_PauseEncoder(AUDIO_RPC_SEND_LONG x)= 27;
 *	HRESULT		AUDIO_RPC_ENC_ToAgent_StopEncoder(AUDIO_RPC_SEND_LONG x)= 28;
 *	HRESULT		AUDIO_RPC_ENC_ToAgent_SetSourceFile(AUDIO_RPC_SEND_LONG x)= 29;
 *	HRESULT		AUDIO_RPC_ENC_ToAgent_Command(AUDIO_RPC_ENC_COMMAND x) = 300;
 *	HRESULT		AUDIO_RPC_ENC_ToAgent_MuteEncoder(AUDIO_RPC_SEND_LONG x) = 301;
 *	HRESULT   	AUDIO_RPC_ENC_ToAgent_SetEncoder(AUDIO_RPC_ENC_INFO) = 302;
 *	HRESULT   	AUDIO_RPC_ENC_ToAgent_SetDVMixer(AUDIO_RPC_ENC_DV_MIXER) = 303;
 *
 *
 *
 *----------------------------------------------------------------------------------------------------
 **/


/**
 * \fn	HRESULT			AUDIO_RPC_ENC_ToAgent_Init(AUDIO_RPC_ENC_INIT);
 * \brief This function inits the all setting encoder needs.
 * \return
 * \param  A struct AUDIO_RPC_ENC_INIT.
 */

	HRESULT   	AUDIO_RPC_ENC_ToAgent_Init(AUDIO_RPC_ENC_INIT x) = 51;


/**
 * \fn	HRESULT			AUDIO_RPC_ENC_ToAgent_SetBitRate(AUDIO_RPC_ENC_SET_BITRATE)
 * \brief This function decides the bit rate dynamically for rate control.
 * \return
 * \param  A struct AUDIO_RPC_ENC_SET_BITRATE.
 */

	HRESULT     AUDIO_RPC_ENC_ToAgent_SetBitRate(AUDIO_RPC_ENC_SET_BITRATE x) = 52;

/**
 * \fn	HRESULT			AUDIO_RPC_ENC_ToAgent_StartEncoder(AUDIO_RPC_SEND_LONG)
 * \fn	HRESULT			AUDIO_RPC_ENC_ToAgent_PauseEncoder(AUDIO_RPC_SEND_LONG)
 * \fn	HRESULT			AUDIO_RPC_ENC_ToAgent_StopEncoder(AUDIO_RPC_SEND_LONG)
 *
 *	which is equivalent to
 *
 * \fn	HRESULT			AUDIO_RPC_ENC_ToAgent_Command(AUDIO_RPC_ENC_COMMAND)
 * \brief This function command encoder to run, pause, stop.
 * \return
 * \param  instance ID.
 */

  	HRESULT		AUDIO_RPC_ENC_ToAgent_StartEncoder(AUDIO_RPC_SEND_LONG x)= 53;
  	HRESULT		AUDIO_RPC_ENC_ToAgent_PauseEncoder(AUDIO_RPC_SEND_LONG x)= 54;
  	HRESULT		AUDIO_RPC_ENC_ToAgent_StopEncoder(AUDIO_RPC_SEND_LONG x)= 55;

        /* Only for simulation */
 	HRESULT		AUDIO_RPC_ENC_ToAgent_SetSourceFile(AUDIO_RPC_ENC_SOURCEFILE x)= 56;

	HRESULT		AUDIO_RPC_ENC_ToAgent_Command(AUDIO_RPC_ENC_COMMAND x) = 57;

/**
 * \fn	HRESULT			AUDIO_RPC_ENC_MuteEncoder(AUDIO_RPC_SEND_LONG x);
 *
 * \brief This function mutes the encoder, so zeros will be encode into bitstream.
 *	It is only for a short-term use.
 * \return
 * \param  A struct AUDIO_RPC_SEND_LONG.
 */

 	HRESULT		AUDIO_RPC_ENC_ToAgent_MuteEncoder(AUDIO_RPC_SEND_LONG x) = 58;

/**
 * \fn	HRESULT			AUDIO_RPC_ENC_SetEncoder(AUDIO_RPC_ENC_INFO);
 *
 * \brief This function configure the encoder. Especially the private info will be sent.
 * \return
 * \param  A struct AUDIO_RPC_ENC_INFO.
 */

	HRESULT   	AUDIO_RPC_ENC_SetEncoder(AUDIO_RPC_ENC_INFO) = 59;

/**
 * \fn	HRESULT   	AUDIO_RPC_ENC_ToAgent_SetDVMixer(AUDIO_RPC_ENC_DV_MIXER)
 *
 * \brief This function configure the DV Mixer before the encoder.
 * \return
 * \param  A struct AUDIO_RPC_ENC_DV_MIXER.
 */

 	HRESULT   	AUDIO_RPC_ENC_ToAgent_SetDVMixer(AUDIO_RPC_ENC_DV_MIXER) = 60;

/**
   This function configure the encoder that Recording is real-time or not.
   If non-realtime is set, it means encoder doesn't need to inform video that output
   is full, and etc.
        0 = real-time
        1 = non-realteim

**/
	HRESULT         AUDIO_RPC_ENC_ToAgent_SetNonRealTime(AUDIO_RPC_SEND_LONG x) = 61;


	HRESULT   	AUDIO_RPC_ENC_ToAgent_SetInputSR(AUDIO_RPC_SEND_LONG x) = 62;

/** AO API ------------------------------------------------------------------------------------------
 *
 *	The AO API is designed for AO filters.
 *
 *	HRESULT   	AUDIO_RPC_AO_ToAgent_Init(AUDIO_RPC_AO_INIT) = 52;
 *	HRESULT		AUDIO_RPC_AO_ToAgent_SetEaqualizer(AUDIO_RPC_AO_SET_EQUALIZER x)= 400;
 *	HRESULT   	AUDIO_RPC_AO_ToAgent_ConfigDelayControl(AUDIO_RPC_AO_CONFIG_DELAY_CONTROL)=402;
 *	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigKaraoke(AUDIO_RPC_AO_CONFIG_KARAOKE) = 403;
 *	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigMixer(AUDIO_RPC_AO_MIXER)=406;
 *	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigPP(AUDIO_RPC_PP_CFG) = 407;
 *  HRESULT		AUDIO_RPC_AO_ToAgent_ConfigMute(AUDIO_RPC_PP_MUTE)= 408;
 *	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigDAC(AUDIO_RPC_AO_DAC)= 409;
 *	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigPrologic(AUDIO_RPC_PP_PROLOGIC)= 410;
 *
 *----------------------------------------------------------------------------------------------------
 **/

/**
 *	\fn	HRESULT		AUDIO_RPC_AO_ToAgent_Init(AUDIO_RPC_AO_INIT)
 *	\brief	To init the Audio output.
 *	\return
 *	\param	a struct AUDIO_RPC_AO_INIT.
 */

 	HRESULT   	AUDIO_RPC_AO_ToAgent_Init(AUDIO_RPC_AO_INIT x) = 81;

/**
 *	\fn HRESULT 	AUDIO_RPC_AO_ToAgent_SetEaqualizer(AUDIO_RPC_AO_SET_EQUALIZER)
 *	\brief	It is used to set a ten-band eqaulizer
 *	\return
 *	\param	a struct of AUDIO_RPC_AO_SET_EQUALIZER.
 */

 	HRESULT		AUDIO_RPC_AO_ToAgent_SetEaqualizer(AUDIO_RPC_AO_SET_EQUALIZER x)= 82;


/**
 *	\fn HRESULT 	AUDIO_RPC_AO_ToAgent_ConfigDelayControl(AUDIO_RPC_AO_CONFIG_DELAY_CONTROL)
 *	\brief	It is used to set the delay control
 *	\return
 *	\param	a struct of AUDIO_RPC_AO_CONFIG_DELAY_CONTROL.
 */

 	HRESULT   	AUDIO_RPC_AO_ToAgent_ConfigDelayControl(AUDIO_AO_RPC_CONFIG_DELAY_CONTROL x)=83;

/**
 *	\fn HRESULT 	AUDIO_RPC_AO_ToAgent_ConfigKaraoke(AUDIO_RPC_AO_CONFIG_KARAOKE)
 *	\brief	It is used to set the Karaoke mode.
 *  \return
 *	\param	a struct of AUDIO_AO_CONFIG_KARAOKE.
 */

 	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigKaraoke(AUDIO_RPC_AO_CONFIG_KARAOKE x) = 84;


/**
 *	\fn	AUDIO_RPC_AO_ToAgent_ConfigMixer(AUDIO_RPC_AO_MIXER)
 *	\brief	It is used to configure the Mixer in different modes.
 *	\return
 *	\param	a struct of AUDIO_RPC_AO_CONFIG_MIXER.
 */

  	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigMixer(AUDIO_RPC_AO_MIXER x)=85;

/**
 *	\fn	AUDIO_RPC_AO_ToAgent_ConfigPP(AUDIO_RPC_PP_CFG)
 *	\brief	Turn on or off for each module in PP.
 *	\return
 *	\param	a struct of AUDIO_RPC_PP_CFG.
 */

  	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigPP(AUDIO_RPC_PP_CFG x) = 86;

/**
 *	\fn	HRESULT		AUDIO_RPC_AO_ToAgent_Mute(AUDIO_RPC_PP_MUTE x);
 *	\brief	To mute AI or AO
 *
 *  If AO is muted, only zeros are sent.
 *	If AI is muted, the sound does not echo out to AO. But it is not responsed to this API.
 *	If decoder is muted, decoder ignores it.
 *	If encoder is muted, encoder ignore it.
 *
 *	\return
 *	\param	instance ID.
 */

   	HRESULT		AUDIO_RPC_AO_ToAgent_Mute(AUDIO_OUT_MUTE_INFO)= 87;

/**
 *	\fn	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigDAC(AUDIO_RPC_AO_DAC)
 *	\brief	To Config AO ADC
 *
 *	\return
 *	\param	instance ID.
 */

 		HRESULT		AUDIO_RPC_AO_ToAgent_ConfigDAC(AUDIO_RPC_AO_DAC)= 88;

/**
 *	\fn	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigPrologic(AUDIO_RPC_PP_PROLOGIC)
 *	\brief	To Config Prologic2
 *
 *	\return
 *	\param	instance ID.
 */

 	HRESULT		AUDIO_RPC_AO_ToAgent_ConfigPrologic(AUDIO_RPC_PP_PROLOGIC)= 89;


        HRESULT         AUDIO_RPC_AO_ToAgent_SPDIFO_Source_Config(AUDIO_RPC_SPDIFO_SOURCE) = 90;

        HRESULT         AUDIO_RPC_AO_ToAgent_ResampleTable(AUDIO_RPC_RESAMPLE_INFO) = 91;

/** AI API ------------------------------------------------------------------------------------------
 *
 *	The AI API is designed for AI filters.
 *
 *	HRESULT   	AUDIO_AI_RPC_ToAgent_ADC0Config(AUDIO_CONFIG_ADC)= 500;
 *	HRESULT   	AUDIO_AI_RPC_ToAgent_ADC1Config(AUDIO_CONFIG_ADC)= 501;
 *	HRESULT   	AUDIO_AI_RPC_ToAgent_SPDIFConfig(AUDIO_CONFIG_SPDIF)= 502;
 *	HRESULT		AUDIO_AI_BACKDOOR_INIT(AUDIO_BACKDOOR_AI_INIT)= 504;
 *	HRESULT   	AUDIO_AI_RPC_ToAgent_SPDIF_ERR_THRESHOLDConfig(AUDIO_CONFIG_SPDIF_ERR)= 505;
 *
 *---------------------------------------------------------------------------------------------------
 **/

/**
 *	\fn HRESULT		AUDIO_AI_RPC_ToAgent_ADC0Config(AUDIO_CONFIG_ADC)
 *	\brief	To init the Audio I2S Input.
 *	\return
 *	\param	a struct AUDIO_CONFIG_ADC
 */

	/*HRESULT   	AUDIO_AI_RPC_ToAgent_ADC0Config(AUDIO_CONFIG_ADC x) = 110; 	*/

  HRESULT		AUDIO_RPC_ToAgent_ADC0_Config(AUDIO_CONFIG_ADC)=110;

/**
 *	\fn HRESULT		AUDIO_AI_RPC_ToAgent_ADC1Config(AUDIO_CONFIG_ADC)
 *	\brief	To init the Audio I2S Input.
 *	\return
 *	\param	a struct AUDIO_CONFIG_ADC
 */

	/*HRESULT   	AUDIO_AI_RPC_ToAgent_ADC1Config(AUDIO_CONFIG_ADC x) = 111; 	*/
    HRESULT		AUDIO_RPC_ToAgent_ADC1_Config(AUDIO_CONFIG_ADC)=111;

/**
 *	\fn HRESULT		AUDIO_AI_RPC_ToAgent_SPDIFConfig(AUDIO_CONFIG_SPDIF)
 *	\brief	To init the Audio SPDIF Input.
 *	\return
 *	\param	a struct AUDIO_CONFIG_SPDIF.
 */

	/*RESULT   	AUDIO_AI_RPC_ToAgent_SPDIFConfig(AUDIO_CONFIG_SPDIF x)= 502;*/
	HRESULT		AUDIO_RPC_ToAgent_SPDIF_Config(AUDIO_CONFIG_SPDIF)=112;

/**
 *	\fn HRESULT		AUDIO_AI_BACKDOOR_INIT(AUDIO_BACKDOOR_AI_INIT )
 *	\brief	To init the Audio Inpu, chanhe interrupt period.
 *	\return
 *	\param	a struct AUDIO_BACKDOOR_AI_INIT.
 */

	/*HRESULT   	AUDIO_AI_BACKDOOR_INIT(AUDIO_BACKDOOR_AI_INIT x)= 504; */
   HRESULT		AUDIO_RPC_ToAgent_AI_BackDoor_Init(AUDIO_BACKDOOR_AI_INIT)=113;


/**
 *	\fn HRESULT		AUDIO_AI_RPC_ToAgent_SPDIF_ERR_THRESHOLDConfig(AUDIO_CONFIG_SPDIF_ERR)
 *	\brief	To init the SPDIF Error threshold.
 *	\return
 *	\param	a struct AUDIO_CONFIG_SPDIF_ERR.
 */

	/*HRESULT   	AUDIO_AI_RPC_ToAgent_SPDIF_ERR_THRESHOLDConfig(AUDIO_CONFIG_SPDIF_ERR x)= 505;  */

  HRESULT		AUDIO_RPC_ToAgent_SPDIF_Err_Threshold_Config(AUDIO_CONFIG_SPDIF_ERR)=114;

  HRESULT		AUDIO_RPC_ToAgent_AIN_Switch_Focus(AUDIO_IN_SOURCE) = 115;
  HRESULT		AUDIO_RPC_ToAgent_AOUT_Copy_Source(AUDIO_OUT_COPY_SOURCE) = 116;
  HRESULT		AUDIO_RPC_ToAgent_AOUT_Volume_Control(AUDIO_VOLUME_CONTROL) = 117;
  HRESULT		AUDIO_RPC_ToAgent_AOUT_SPDIF_Source(AUDIO_OUT_SPDIF_SOURCE) = 118;
  HRESULT		AUDIO_RPC_ToAgent_Karaoke_Control(AUDIO_KARAOKE_CONTROL_INFO) = 119;
  HRESULT 		AUDIO_RPC_ToAgent_AIN_Mute(AUDIO_IN_MUTE_INFO) = 120;
  HRESULT		AUDIO_RPC_ToAgent_AOUT_Drop_Sample(AUDIO_DROP_SAMPLE) = 121;
  HRESULT		AUDIO_RPC_ToAgent_AOUT_Pink_White_Noise(AUDIO_P_W_NOISE_CFG) = 122;
  HRESULT		AUDIO_RPC_ToAgent_AOUT_Send_Spectrum_Data(AUDIO_SPECTRUM_CFG) = 123;
  /*HRESULT		AUDIO_RPC_ToAgent_AIN_Config_TSD(AUDIO_IN_CONFIG_TSD) = 124;*/
  HRESULT       AUDIO_RPC_ToAgent_PlaySoundEvent (AUDIO_SOUND_EVENT ) = 125;

  HRESULT       AUDIO_RPC_ToAgent_AOUT_ResetPin(long)=126;
  HRESULT		AUDIO_RPC_ToAgent_AFC_Config(AUDIO_CONFIG_AFC)=127;
  HRESULT		AUDIO_RPC_ToAgent_Audistry_Config(AUDISTRY_CONFIG_COMMAND)=128;
  HRESULT       AUDIO_RPC_ToAgent_HDMI_Mute (AUDIO_HDMI_MUTE_INFO ) = 129;
  HRESULT             AUDIO_RPC_ToAgent_ADC2_Config(AUDIO_CONFIG_ADC)=130;

  HRESULT       AUDIO_RPC_ToAgent_AOUT_HDMI_Set (AUDIO_HDMI_SET ) = 131;
  HRESULT       AUDIO_RPC_ToAgent_AO_Only_Switchfocus(AUDIO_RPC_AO_FOCUS) = 132;
  HRESULT		AUDIO_RPC_ToAgent_AIN_Data_Measurement(AUDIO_IN_DATA_MEASURE) = 133;

/** for TV hardware **/
/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_BBADC_Config(AUDIO_RPC_ADC_CONFIG)
 *	\brief	To init the Audio BBADC Input.
 *	\return
 *	\param	a struct AUDIO_RPC_BBADC_CONFIG
 */     	
HRESULT		AUDIO_RPC_ToAgent_BBADC_Config(AUDIO_RPC_BBADC_CONFIG)=150;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_I2SI_Config(AUDIO_RPC_I2S_CONFIG)
 *	\brief	To init the Audio I2S Input.
 *	\return
 *	\param	a struct AUDIO_RPC_I2SI_CONFIG
 */     	
HRESULT		AUDIO_RPC_ToAgent_I2SI_Config(AUDIO_RPC_I2SI_CONFIG)=151;
		
/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SPDIFI_Config(AUDIO_RPC_SPDIF_CONFIG)
 *	\brief	To init the Audio SPDIF Input.
 *	\return
 *	\param	a struct AUDIO_RPC_SPDIFI_CONFIG.
 */     	
HRESULT		AUDIO_RPC_ToAgent_SPDIFI_Config(AUDIO_RPC_SPDIFI_CONFIG)=152;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_ChangeInputSource(AUDIO_RPC_SPDIF_CONFIG)
 *	\brief	To change input source
 *	\return
 *	\param	a struct AUDIO_RPC_SPDIFI_CONFIG.
 */
HRESULT		AUDIO_RPC_ToAgent_ChangeInputSource(AUDIO_RPC_IPT_SRC) = 153;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SET_ATV_CLOCK(AUDIO_RPC_SET_ATV_CLOCK)
 *	\brief	To set ATV CLOCK.
 *	\return
 *	\param.
 */
HRESULT		AUDIO_RPC_ToAgent_SET_ATV_CLOCK(AUDIO_RPC_SET_ATV_CLOCK) = 154;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_INOUT_CH_SELECT(AUDIO_RPC_INOUT_CH_SELECT)
 *	\brief	To select AI in-out ch.
 *	\return
 *	\param.
 */
HRESULT		AUDIO_RPC_ToAgent_INOUT_CH_SELECT(AUDIO_RPC_INOUT_CH_SELECT) = 155;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SET_FS_CLOCKSRC(AUDIO_RPC_SET_FS_CLOCKSRC)
 *	\brief	To select AI fs clocksrc
 *	\return
 *	\param.
 */
HRESULT		AUDIO_RPC_ToAgent_SET_FS_CLOCKSRC(AUDIO_RPC_SET_FS_CLOCKSRC) = 156;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SET_PATH_DATA_OUT(AUDIO_RPC_SET_PATH_DATA_OUT)
 *	\brief	To select AI fs clocksrc
 *	\return
 *	\param.
 */
HRESULT		AUDIO_RPC_ToAgent_SET_PATH_DATA_OUT(AUDIO_RPC_SET_PATH_DATA_OUT) = 157;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SET_INTERLEAVE_OUT(AUDIO_RPC_SET_INTERLEAVE_OUT)
 *	\brief	To select AI interleave mode
 *	\return
 *	\param.
 */
HRESULT		AUDIO_RPC_ToAgent_SET_INTERLEAVE_OUT(AUDIO_RPC_SET_INTERLEAVE_OUT) = 158;

HRESULT		AUDIO_RPC_ToAgent_SET_CHANNEL_OUT_SWAP(AUDIO_RPC_AO_CHANNEL_OPT_SWAP) = 159;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SetAuthorityKey(int)
 *	\brief	To inform f/w authority key
 *	\return
 *	\param	a key
 */
HRESULT		AUDIO_RPC_ToAgent_SetAuthorityKey(long) = 160;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_GET_SPDIF_CS(AUDIO_SPDIF_CS)
 *	\To get Audio in or Audio output SPDIF CS
 *	\return
 */
HRESULT       AUDIO_RPC_ToAgent_GET_SPDIF_CS(AUDIO_SPDIF_CS)=161;

/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_SET_SIF_ADC_INIT(AUDIO_RPC_SET_SIF_ADC_INIT)
 *	\To decide SIF ADC init flow enable or not
 *	\return
 */
HRESULT       AUDIO_RPC_ToAgent_SET_SIF_ADC_INIT(AUDIO_RPC_SET_SIF_ADC_INIT)=162;

/** temp **/

  HRESULT		AUDIO_RPC_ToAgent_HDMI_OUT_EDID(AUDIO_HDMI_OUT_EDID_DATA)=200;
  HRESULT		AUDIO_RPC_ToAgent_HDMI_INFO(HDMI_INFO)=201;

  HRESULT		AUDIO_RPC_ToAgent_UpdatePTS(AUDIO_RPC_PTS_INFO)=203;
  HRESULT		AUDIO_RPC_ToAgent_EndOfStream(AUDIO_RPC_SENDPIN_LONG)=204;
  HRESULT		AUDIO_RPC_ToAgent_SwitchFocus(AUDIO_RPC_FOCUS)=205;

  HRESULT		AUDIO_RPC_ToAgent_DAC_I2S_Config(AUDIO_CONFIG_DAC_I2S)=206;
  HRESULT		AUDIO_RPC_ToAgent_DAC_SPDIF_Config(AUDIO_CONFIG_DAC_SPDIF)=207;

  HRESULT		AUDIO_RPC_ToAgent_HDMI_OUT_VSDB(AUDIO_HDMI_OUT_VSDB_DATA)=208;
  
  HRESULT		AUDIO_RPC_ToAgent_HDMI_OUT_EDID2(AUDIO_HDMI_OUT_EDID_DATA2)=209;

  HRESULT		AUDIO_RPC_ToAgent_DecoderConfig(AUDIO_RPC_DECCFG)=212;

  HRESULT       AUDIO_RPC_ToAgent_NightMode(AUDIO_RPC_NIGHTMODE)=213;

  HRESULT       AUDIO_RPC_ToAgent_PP_InitPin(long)=214;

 /**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_AskDebugMemoryAddress(unsigned long x)
 *	\brief	Ask audio firmware to return back an adress for debug message
 *	\return
 *	\param	a pointer to the virtual address of the audio firmware
 *
 *	the x is a pointer which point to the starting address of the data structure AUDIO_RPC_DEBUG_MEMORY.
 */

  HRESULT		AUDIO_RPC_ToAgent_AskDebugMemoryAddress(unsigned long x) = 215;

/* Audio PP function RPC call */
  HRESULT       AUDIO_RPC_ToAgent_PP_Config(AUDIO_PP_CONFIG)=216;
  HRESULT       AUDIO_RPC_ToAgent_PP_SRC_Config(AUDIO_SRC_CONFIG)=217;
  HRESULT       AUDIO_RPC_ToAgent_PP_PL2_Config(AUDIO_PROLOGIC2_CONFIG)=218;
  HRESULT       AUDIO_RPC_ToAgent_PP_MIXER_Config(AUDIO_MIXER_CONFIG)=219;
  HRESULT       AUDIO_RPC_ToAgent_PP_BASS_MANAGEMENT_Config(AUDIO_BASS_MANAGEMENT_CONFIG)=220;
  HRESULT       AUDIO_RPC_ToAgent_PP_KEY_SHIFT_Config(AUDIO_KEY_SHIFT_CONFIG)=221;
  HRESULT       AUDIO_RPC_ToAgent_PP_REVERB_Config(AUDIO_REVERB_CONFIG)=222;
  HRESULT 		AUDIO_RPC_ToAgent_PP_COMFORT_LISTEN(AUDIO_AGC_MODE)=223;
  HRESULT       AUDIO_RPC_ToAgent_PP_EQ_Config(AUDIO_EQUALIZER_CONFIG)=224;
  HRESULT       AUDIO_RPC_ToAgent_PP_VOCAL_REMOVER_Config(AUDIO_VOCAL_REMOVER_CONFIG)=225;

  AUDIO_RPC_DEC_FORMAT_INFO AUDIO_RPC_DEC_ToAgent_GetAudioFormatInfo(long instanceID) = 226;
  HRESULT       AUDIO_RPC_ToAgent_PP_DVS_Config(AUDIO_DVS_CONFIG)=227;
  HRESULT       AUDIO_RPC_ToAgent_PP_TSXT_Config(AUDIO_RPC_TSXT)=228; 
  HRESULT       AUDIO_RPC_ToAgent_PP_PTS_MIXER_Config(AUDIO_RPC_PTS_MIXER_CONFIG)=229;
  HRESULT       AUDIO_RPC_ToAgent_PP_BASSBACK_PCBU_Config(AUDIO_RPC_PCBU_BASSBACK)=230; 
  HRESULT       AUDIO_RPC_ToAgent_PP_BASSBACK_TV_Config(AUDIO_RPC_TV_BASSBACK)=231;
  HRESULT       AUDIO_RPC_ToAgent_PP_BASSBACK_Change_Bass_Gain(AUDIO_RPC_TV_BASSBACK_CHANGE_BASS_GAIN)=232;  
  HRESULT       AUDIO_RPC_ToAgent_PP_AGC(AUDIO_RPC_PP_AGC)=233;
  HRESULT       AUDIO_RPC_ToAgent_PP_TRUVOLUME_Config(AUDIO_RPC_TRUVOLUME)=234;  
  HRESULT       AUDIO_RPC_ToAgent_PP_FREQ_EQ_Config(AUDIO_RPC_FREQ_EQ)=235; 
  
  HRESULT       AUDIO_RPC_ToAgent_PP_ASF_ON_OFF_Config(AUDIO_RPC_PP_ASF_ON_OFF)=236; 
  HRESULT       AUDIO_RPC_ToAgent_PP_ASF_BALANCE_Config(AUDIO_RPC_PP_ASF_BALANCE)=237; 
  HRESULT       AUDIO_RPC_ToAgent_PP_ASF_VOLUME_Config(AUDIO_RPC_PP_ASF_MASTER_VOLUME)=238; 

  HRESULT		AUDIO_RPC_ToAgent_SubChannel(AUDIO_RPC_SUBCHANNEL)=239;

  HRESULT		AUDIO_RPC_ToAgent_TrueHD_LosslessMode(AUDIO_RPC_TRUEHD_LOSSLESSMODE)=240;  

  HRESULT       AUDIO_RPC_ToAgent_PP_TSHD_Config(AUDIO_RPC_TSHD)=243;
/* Audio AO function RPC call */  
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetMode(AUDIO_RPC_LGSE_SETMODE)=244;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetMain(AUDIO_RPC_LGSE_SETMAIN)=245;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn000(AUDIO_RPC_LGSE_SETFN000)=246;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn001(AUDIO_RPC_LGSE_SETFN001)=247;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn009(AUDIO_RPC_LGSE_SETFN009)=248;
  AUDIO_RPC_LGSE_RETURNVAL       AUDIO_RPC_ToAgent_AO_LGSE_SetFn010(AUDIO_RPC_LGSE_SETFN010)=249;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn004(AUDIO_RPC_LGSE_SETFN004)=256;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn005(AUDIO_RPC_LGSE_SETFN005)=257;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn008(AUDIO_RPC_LGSE_SETFN008)=258;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn014(AUDIO_RPC_LGSE_SETFN014)=259;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn017(AUDIO_RPC_LGSE_SETFN017)=260;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn019(AUDIO_RPC_LGSE_SETFN019)=261;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn022(AUDIO_RPC_LGSE_SETFN022)=262;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn018(AUDIO_RPC_LGSE_SETFN018)=263;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn026(AUDIO_RPC_LGSE_SETFN026)=264;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn027(AUDIO_RPC_LGSE_SETFN027)=265;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn028(AUDIO_RPC_LGSE_SETFN028)=266;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn029(AUDIO_RPC_LGSE_SETFN029)=267;
  AUDIO_RPC_LGSE_RETURNVAL       AUDIO_RPC_ToAgent_AO_LGSE_GetData(AUDIO_RPC_LGSE_GETDATA)=268;
  HRESULT       AUDIO_RPC_ToAgent_AO_LGSE_SetFn024(AUDIO_RPC_LGSE_SETFN024)=269;
  

/* get decoder seeking capacity  */
AUDIO_RPC_DEC_SEEKING_CAP  AUDIO_RPC_DEC_ToAgent_GetAudioDecoderSeekCap(AUDIO_DEC_TYPE dec_type)=270;

    
/* License Control */
/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_Capability_SetMask(long x)
 *	\brief	Tell Audio firmware which decoder formats could be turned on.
 *	\return
 *	\param	a mask value. the upper 16 bits are alway 0, the last 8 bits are a mask.
 *
 */
	HRESULT					AUDIO_RPC_ToAgent_Capability_SetMask(long)=250;

/* get audio format from AI */
AUDIO_RPC_AIN_FORMAT_INFO AUDIO_RPC_AIN_ToAgent_GetAudioFormatInfo(long instanceID) = 271;


/**
 *  \fn HRESULT     AUDIO_RPC_ToAgent_AudioHalt(long)
 *  \brief To suspend audio CPU.
 *  This function forces audio CPU to idle loop.
 *  \return
 *  \param  reserved for future use
 */

   HRESULT      AUDIO_RPC_ToAgent_AudioHalt(long)=251;

/**
 *	\fn HRESULT	AUDIO_RPC_ToAgent_Full_Capability_SetMask(long x)
 *	\brief	Tell Audio firmware which decoder / encoder formats could be turned on.
 *	\return
 *	\param	a mask value. the upper 16 bits are alway 0, the last 8 bits are a mask.
 *
 */
	HRESULT		AUDIO_RPC_ToAgent_Full_Capability_SetMask(AUDIO_LICENSE_STATUS_CONFIG)=252;
	AUDIO_RPC_PRIVATEINFO_RETURNVAL		AUDIO_RPC_ToAgent_PrivateInfo(AUDIO_RPC_PRIVATEINFO_PARAMETERS)=253;	

/* License Control */
/**
 *	\fn HRESULT		AUDIO_RPC_ToAgent_Capability_SetPassThroughMode_0_svc(AUDIO_PASSTHROUGH_INFO)
 *	\brief	Tell Audio firmware which passthough mode decoder should support.
 *	\return
 *	\param	a mask value. the upper 16 bits are alway 0, the last 8 bits are a mask.
 *
 */
	HRESULT					AUDIO_RPC_ToAgent_Capability_SetPassThroughMode(AUDIO_PASSTHROUGH_INFO)=254;

    USB_DEVICE_CONFIG_INFO AUDIO_RPC_ToAgent_AI_Device_USBinfo(AUDIO_AI_DEVICE_USB_INFO)=255;
    
/* general purpose */
	HRESULT		AUDIO_RPC_ToAgent_Set_Dummy_Value(AUDIO_DUMMY_DATA)= 300;
  }=0;
}=201;

