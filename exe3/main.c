#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_G = 6;
const int LED_PIN_R = 4;
const int BTNG_PIN = 26;
const int BTNR_PIN = 28;

int main() {
  stdio_init_all();

  int state_g = 0;
  int state_r = 0;

  gpio_init(LED_PIN_G);
  gpio_init(LED_PIN_R);
  gpio_init(BTNG_PIN);
  gpio_init(BTNR_PIN);

  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(BTNG_PIN, GPIO_IN);
  gpio_set_dir(BTNR_PIN, GPIO_IN);

  gpio_pull_up(BTNG_PIN); 
  gpio_pull_up(BTNR_PIN); 

  while (true) {
    if (!gpio_get(BTNG_PIN)) {
      if(state_g == 0){
        gpio_put(LED_PIN_G, 1);
        state_g = 1;
      }
      else{
        gpio_put(LED_PIN_G, 0);
        state_g = 0;
      } 
    }
    
    else if (!gpio_get(BTNR_PIN)) {
      if(state_r == 0){
        gpio_put(LED_PIN_R, 1);
        state_r = 1;
      }
      else{
        gpio_put(LED_PIN_R, 0);
        state_r = 0;
      } 
    } 
  }
}