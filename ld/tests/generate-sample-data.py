#!/usr/bin/env python3
"""
Generates a sample data csv file that can be used to test regexps for the `compare-real-csv.py` script
"""


def stm32g01():
    """
    Typed in by inspection of the chart on https://www.st.com/en/microcontrollers-microprocessors/stm32g0x1.html
    on 2024-01-17
    """
    for package in ['j', 'f', 'g', 'k', 'c']:
        print(f"stm32g031{package}4,16k,8k")
        print(f"stm32g031{package}6,32k,8k")
        print(f"stm32g041{package}6,32k,8k")
    for package in ['f', 'g', 'k', 'c']:
        print(f"stm32g051{package}6,32k,18k")
        print(f"stm32g061{package}6,32k,18k")
    for package in ['f', 'g', 'k', 'c', 'y']:
        print(f"stm32g031{package}8,64k,8k")
        print(f"stm32g041{package}8,64k,8k")
        print(f"stm32g051{package}8,64k,18k")
        print(f"stm32g061{package}8,64k,18k")
    for package in ['g', 'k', 'c', 'r']:
        print(f"stm32g071{package}8,64k,36k")
    for package in ['g', 'k', 'c', 'r', 'e']:
        print(f"stm32g071{package}b,128k,36k")
        print(f"stm32g081{package}b,128k,36k")
    for package in ['k', 'c', 'r', 'm', 'v']:
        print(f"stm32g0b1{package}b,128k,144k")
        print(f"stm32g0b1{package}c,256k,144k")
        print(f"stm32g0c1{package}c,256k,144k")
    for package in ['k', 'c', 'r', 'm', 'v', 'n']:
        print(f"stm32g0b1{package}e,512k,144k")
        print(f"stm32g0c1{package}e,512k,144k")

stm32g01()