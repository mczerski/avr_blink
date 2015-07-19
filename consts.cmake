set(PROJECT_NAME avr_test)
set(PROG_TYPE usbasp)
# extra arguments to avrdude: baud rate, chip type, -F flag, etc.
set(PROG_ARGS -F)

# Variables regarding the AVR chip
set(MCU   atmega328p)
set(F_CPU 8000000)
set(BAUD  38400)
set(TEXT  0x0000)

