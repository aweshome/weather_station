/*
 * power_cfg.h
 *
 * Created: 04.11.2016 20:44:09
 *  Author: Adam
 */ 


#ifndef POWER_CFG_H_
#define POWER_CFG_H_

void power_peripherials_disable(void);
void power_sleep_mode_cfg(void);
void power_sleep_enable(void);
void power_sleep_disable(void);
uint8_t power_sleep_action(void);


#endif /* POWER_CFG_H_ */