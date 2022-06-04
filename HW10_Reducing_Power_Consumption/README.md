[HW10 FP Power Consumption Calculation Sheet](https://docs.google.com/spreadsheets/d/1yEKhG9K9GtEmH_HGzw88_qT8BmbdluEg/edit?usp=sharing&ouid=112547200637168634292&rtpof=true&sd=true)
 

## Ways for reducing the power consumption of the FM Tuner

The design of my final project was made with the idea of a proof of concept study. Without a doubt, it needs to be revised if the aim pursued is a marketbale product. Hereafter are some ideas to reach that goal: 

* Use a simpler microcontroller board: there is no need of a 32-bit processor.
* Replace the TFT LCD display by a 2 or 4 lines LCD HD44870-based display (I2C interfaced. Indeed TFT backlights are significant power consumers.
* Use a compact rechargeable LiPo battery along with a step-up or a step-down converter depending of the available battery voltage. The converter must have the highest power conversion effiency.
* Possibly replace the class-AB stereo audio module by a class-D one. However beware of the switching frequency that could disturb the audio quality!
* Replace the RDA5807M tuner IC by a part of the Si7xxx series. In this series, some chips can be powered with 5Vdc which is the minimum voltage used by the actual stereo amplifier.
* Pack everything in a nice enclosure 













