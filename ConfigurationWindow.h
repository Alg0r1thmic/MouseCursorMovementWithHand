#ifndef CONFIGURATIONWINDOW_H
#define CONFIGURATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class ConfigurationWindow;
}

class ConfigurationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ConfigurationWindow(QWidget *parent = 0);
    ~ConfigurationWindow();
    
private slots:
    void on_in_image_size_valueChanged(int value);
    void on_in_y_min_valueChanged(int value);
    void on_in_y_max_valueChanged(int value);
    void on_in_cb_min_valueChanged(int value);
    void on_in_cb_max_valueChanged(int value);
    void on_in_cr_min_valueChanged(int value);
    void on_in_cr_max_valueChanged(int value);
    void on_in_open_kernel_valueChanged(int value);
    void on_in_close_kernel_valueChanged(int value);
    void on_in_blur_kernel_valueChanged(int value);
    void on_in_blur_sigma_valueChanged(int value);
    void on_in_image_thresh_valueChanged(int value);
    void on_in_area_thresh_valueChanged(int value);
    void on_in_dp_epsilon_valueChanged(int value);
    void on_in_dt_min_valueChanged(int value);
    void on_in_dt_max_valueChanged(int value);
    void on_in_at_min_valueChanged(int value);
    void on_in_at_max_valueChanged(int value);
    void on_in_rh_thresh_valueChanged(int value);
    void on_in_rpd_thresh_valueChanged(int value);
    void on_in_fm_radius_valueChanged(int value);
    void on_in_kf_noise_valueChanged(int value);
    void on_in_fwp_th_valueChanged(int value);
    void on_in_fea_th_valueChanged(int value);
    void on_in_fed_th_valueChanged(int value);
    void on_pushButton_clicked();
    void on_in_tx_valueChanged(int value);
    void on_in_ty_valueChanged(int value);
    void on_in_bx_valueChanged(int value);
    void on_in_by_valueChanged(int value);

private:
    Ui::ConfigurationWindow *ui;
};

#endif // CONFIGURATIONWINDOW_H
