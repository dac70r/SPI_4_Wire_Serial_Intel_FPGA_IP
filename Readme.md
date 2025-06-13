# EtherCAT Base Project on FPGA w/ ESC

## Features
- NIOS II Softcore processor on 10CL040 
- EtherCAT Stack Code for ESC (Functional)
- Objects: 1 Input 1 Output (Loopback Configuration: Assign Output to Input)
- DC Sync Disabled

# Update 15/5/2025
- Bug fix: If more than 1 input and 1 output (EtherCAT objects) is defined, EtherCAT will go into SAFEOP INIT ERROR State after running for an arbitrary amount of time. SPI driver will loop indefinitely, fixed issued by adding a timeout condition. 
- Improvement: Adopted and modified original SPI API by Altera in this design. Original API is already Full-Duplex.

# Update 28/5/2025
- Errors: EtherCAT SM may abruptly change from 'OP' to 'SAFEOP'.
- How to download the working project: Flash .sof -> Run the lastest project configutaion within Eclipse.

# Links 
Learn NIOS Interrupts: https://www.youtube.com/watch?v=HpiEGok8vGU&t=540s