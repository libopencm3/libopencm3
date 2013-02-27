------------------------------------------------------------------------------
README
------------------------------------------------------------------------------

This example program demonstrates SPI transceive with DMA on Lisa/M 2.0 board 
(http://paparazzi.enac.fr/wiki/Lisa/M_v20 for details).

The terminal settings for the receiving device/PC are 9600 8n1.

The example expects a loopback connection between the MISO and MOSI pins on
SPI1. The DRDY and SS pins (on the Lisa/M v2.0 SPI1 connector) are used as
GPIO to time the tx and rx ISRs, respectively. Use a scope or logic analyzer.

The tx length is incremented, followed by the rx length, after which the tx is
decremented, then the rx is decremented. This is repeated in a loop. In this
example, rx lengths longer than tx lengths are handled by using two dma transmits
one after the other, handled inside the tx dma ISR.
