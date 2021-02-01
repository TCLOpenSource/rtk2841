#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/lg1k/pms.h>
#include <linux/platform_device.h>
#include <linux/regulator/driver.h>
#include <linux/regulator/machine.h>
#include <linux/regulator/of_regulator.h>

static int lg1k_regulator_get_voltage(struct regulator_dev *regdev)
{
	return lg1k_pms_get_cpuvolt(0);
}

static int lg1k_regulator_set_voltage(struct regulator_dev *regdev,
                                      int min_uV, int max_uV,
                                      unsigned *selector)
{
	return lg1k_pms_set_cpuvolt(0, min_uV);
}

static struct regulator_ops lg1k_regulator_ops = {
	.get_voltage = lg1k_regulator_get_voltage,
	.set_voltage = lg1k_regulator_set_voltage,
};

static int lg1k_regulator_probe(struct platform_device *pdev)
{
	struct regulator_desc *desc;
	struct regulator_init_data *init_data;
	struct regulator_config config;
	struct regulator_dev *regdev;
	int err = 0;

	desc = devm_kzalloc(&pdev->dev, sizeof(struct regulator_desc),
	                    GFP_KERNEL);
	if (!desc) {
		err = -ENOMEM;
		goto quit;
	}

	desc->name = dev_name(&pdev->dev);
	desc->type = REGULATOR_VOLTAGE;
	desc->owner = THIS_MODULE;
	desc->continuous_voltage_range = true;
	desc->ops = &lg1k_regulator_ops;

	init_data = of_get_regulator_init_data(&pdev->dev, pdev->dev.of_node, desc);
	if (!init_data) {
		err = -EINVAL;
		goto quit;
	}

	memset(&config, 0, sizeof(struct regulator_config));
	config.dev = &pdev->dev;
	config.init_data = init_data;
	config.of_node = pdev->dev.of_node;

	regdev = regulator_register(desc, &config);
	if (IS_ERR(regdev)) {
		err = PTR_ERR(regdev);
		goto quit;
	}

	platform_set_drvdata(pdev, regdev);
quit:
	return err;
}

static int lg1k_regulator_remove(struct platform_device *pdev)
{
	struct regulator_dev *regdev = platform_get_drvdata(pdev);
	regulator_unregister(regdev);
	return 0;
}

static struct of_device_id lg1k_regulator_id[] = {
	{ .compatible = "lge,lg115x-regulator", },
	{ /* sentinel */ }
};

static struct platform_driver lg1k_regulator_driver = {
	.probe	= lg1k_regulator_probe,
	.remove	= lg1k_regulator_remove,
	.driver	= {
		.name		= "lg115x-regulator",
		.owner		= THIS_MODULE,
		.of_match_table	= lg1k_regulator_id,
	},
};

module_platform_driver(lg1k_regulator_driver);

MODULE_AUTHOR("Jongsung Kim <neidhard.kim@lge.com>");
MODULE_DESCRIPTION("LG1K regulator");
MODULE_LICENSE("GPL");
