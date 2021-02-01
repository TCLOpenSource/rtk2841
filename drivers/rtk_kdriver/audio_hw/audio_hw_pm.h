#ifndef AUDIO_HW_PM_H
#define AUDIO_HW_PM_H

struct device;
struct audio_hw_pm;

struct audio_hw_pm *audio_hw_pm_create(struct device *dev);

void audio_hw_pm_destroy(struct audio_hw_pm *pm);

int audio_hw_pm_suspend(struct audio_hw_pm *pm);

int audio_hw_pm_resume(struct audio_hw_pm *pm);

#endif /* AUDIO_HW_PM_H */
