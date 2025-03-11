#define DT_DRV_COMPAT sample_sample

#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/i2c.h>

#if DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) == 0
#warning "sample driver enabled without any devices"
#endif


struct sample_data {
    uint8_t blah;
}

struct sample_config {
    struct i2c_dt_spec i2c;
}

static void sample_init(const struct device *dev)
{

}

static void sample_sample_fetch(const struct device *dev)
{

}

static void sample_channel_get(const struct device *dev, enum sensor_channel, struct sensor_value *val)
{

}

static const struct sensor_driver_api sample_api = {
	.sample_fetch = &sample_sample_fetch,
	.channel_get = &sample_channel_get,
};

#define SAMPLE_DEFINE(inst)                             \
    static struct sample_data sample_data_##inst;       \
    static struct sample_config sample_config_##inst =  \
    {                                                   \
        .i2c = I2C_DT_SPEC_INST_GET(inst),              \
    };                                                  \
    DEVICE_DT_INST_DEFINE(inst,                         \
                          sample_init,                  \
                          NULL,                         \
                          &sample_data_##inst,          \
                          &sample_config_##inst,        \
                          POST_KERNEL,                  \
                          CONFIG_SENSOR_INIT_PRIORITY,  \
                          &sample_api);

DT_INST_FOREACH_STATUS_OKAY(SAMPLE_DEFINE);