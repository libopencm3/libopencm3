------------------------------------------------------------------------------
README
------------------------------------------------------------------------------

This program exercises the SSP1 peripheral on Jellybean's LPC43xx.

   Jellybean (connector)
    P9 SPI
 |-----------------|
 | Pin2  Pin4 Pin6 |
||------|          |
|| Pin1 |Pin3 Pin5 |
||------|----------|
|-------|

SSP1_MISO: Jellybean P9 SPI Pin6
SSP1_MOSI: Jellybean P9 SPI Pin4
SSP1_SCK:  Jellybean P9 SPI Pin2
SSP1_SSEL: Jellybean P9 SPI Pin3
GND: Can be connected to P12 SD Pin1

PCLK clock source is PLL1 288MHz (from IRC 96MHz boot from SPIFI)
Freq = PCLK / (CPSDVSR * [SCR+1]).

By default (CPSDVSR=0 => Means MAX Divisor)
SSP1->CR0->SCR = 0x00 => CLK Freq 1.126MHz
SSP1->CR0->SCR = 0x01 => MOSI Freq 566.9KHz
...

Test Oscilloscpe:
SCR=0, CPSDVSR=32 => CLK 9.025MHz
SCR=1,  CPSDVSR=2 => CLK 73MHz
SCR=2,  CPSDVSR=2 => CLK 49MHz
SCR=4,  CPSDVSR=2 => CLK 29MHz
SCR=8,  CPSDVSR=2 => CLK 16MHz
SCR=16, CPSDVSR=2 => CLK 8.5MHz
SCR=32, CPSDVSR=2 => CLK 4.386MHz
SCR=64, CPSDVSR=2 => CLK 2.227MHz
SCR=1, CPSDVSR=64 => CLK 2.262MHz

Theory:
SCR=0,  CPSDVSR=32 => 288MHz / (32*(0+1) = 9MHz
SCR=1,  CPSDVSR=2 => 288MHz / (2*(1+1) = 72MHz
SCR=4,  CPSDVSR=2 => 288MHz / (2*(4+1) = 28.8MHz
SCR=32, CPSDVSR=2 => 288MHz / (2*(32+1) = 4.364MHz
SCR=64, CPSDVSR=2 => 288MHz / (2*(64+1)) = 2.2154MHz
SCR=128, CPSDVSR=2 => 288MHz / (2*(128+1)) = 1.116MHz
SCR=1, CPSDVSR=64 => 288MHz / (64*(1+1)) = 2.25MHz
