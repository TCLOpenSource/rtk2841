#!/bin/bash

echo "#!/bin/sh" > ./a.sh

#find makefile and echo not do kasan makefile into sh file
find ./ -name Makefile | awk -F '.' '{print "echo KASAN_SANITIZE := n > ./tmp";print "cat ."$2" >> tmp";print "cp ./tmp ."$2;}' >> ./a.sh

chmod u+x ./a.sh
./a.sh


find crypto/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find drivers/video/backlight/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find drivers/net/wireless/realtek/rtlwifi -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find drivers/usb/host -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find drivers/media/usb/gspca -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find drivers/media/usb/gspca -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find drivers/bluetooth -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find arch/arm/mach-rtd* -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'

# add driver folder that you want to check it by kasan
#find drivers/thermal/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
#find drivers/usb/host/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
#find drivers/mmc/host/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
#find drivers/i2c/busses/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
#find drivers/net/ethernet/realtek/ -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'




# add kdriver folder that you want to check it by kasan
cd drivers/rtk_kdriver
find ./atsc3_dmx -name Makefile | xargs sed -i '/KASAN_SANITIZE/d' 
find ./mcp -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./hdcp -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./dolby_IDK_1_4_3 -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./cec -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./demux -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./tp -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./diseqc -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./tvscalercontrol -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./pwm -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./dolbyvision_edr -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./vdec -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./gal -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./dolby_IDK_1_1_12 -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./cw -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./memc_isr -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
find ./md -name Makefile | xargs sed -i '/KASAN_SANITIZE/d'
cd - 
