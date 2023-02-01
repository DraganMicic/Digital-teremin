# Digital-teremin
Digital musical instrument based on distance sensors and 8-bit PIC microcontroler. High school project. (2017)

[Youtube demo video](https://www.youtube.com/watch?v=chjX0MDBCEE)

This Theremin is composed of two probes connected to an application, that processes the information. Each probe is made of one IR distance click, an MCU (PIC18f45k22) and a USB UART click for serial communication with a computer.

The two IR distance click boards™ are the fun part of this device – they are infra-red light sensors that detect the distance between the probes and the hands of the person using the Theremin. The MCU calculates that data and sends it to the computer over UART.

The processing app on the computer generates a sound of a certain frequency and amplitude.

By moving the hand over the right probe we change the frequency, and by moving the hand above the left probe we change the amplitude.
