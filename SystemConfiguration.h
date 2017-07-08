#ifndef SYSTEMCONFIGURATION_H
#define SYSTEMCONFIGURATION_H

class SystemConfiguration
{
public:
    SystemConfiguration();
    void loadDefaults();
    void saveSettings();
    void loadSettings();

    // skin detection settings
    static int y_min;
    static int y_max;
    static int cr_min;
    static int cr_max;
    static int cb_min;
    static int cb_max;
    static int image_size;

    // preprocessing settings
    static int opening_kernel_size;
    static int closing_kernel_size;
    static int blur_kernel_size;
    static double blur_sigma;
    static int image_threshold;

    // contour settings
    static int area_thresh;
    static int dp_epsilon;

    // elemination settings
    static int dt_min;
    static int dt_max;
    static int at_min;
    static int at_max;
    static double rh_thresh;
    static int rpd_thresh;

    // point management settings
    static int fm_radius;
    static double kf_noise;
    static int fwp_thresh;
    static int fea_thresh;
    static int fed_thresh;
    static int topX;
    static int topY;
    static int bottomX;
    static int bottomY;
};

#endif // SYSTEMCONFIGURATION_H
