EXTERN(vector_table)
ENTRY(reset_handler)
MEMORY
{
 ram (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
 rom (rx) : ORIGIN = 0x08000000, LENGTH = 64K
}
SECTIONS
{
 .text : {
  *(.vectors)
  *(.text*)
  . = ALIGN(4);
  *(.rodata*)
  . = ALIGN(4);
 } >rom
 .preinit_array : {
  . = ALIGN(4);
  __preinit_array_start = .;
  KEEP (*(.preinit_array))
  __preinit_array_end = .;
 } >rom
 .init_array : {
  . = ALIGN(4);
  __init_array_start = .;
  KEEP (*(SORT(.init_array.*)))
  KEEP (*(.init_array))
  __init_array_end = .;
 } >rom
 .fini_array : {
  . = ALIGN(4);
  __fini_array_start = .;
  KEEP (*(.fini_array))
  KEEP (*(SORT(.fini_array.*)))
  __fini_array_end = .;
 } >rom
 .ARM.extab : {
  *(.ARM.extab*)
 } >rom
 .ARM.exidx : {
  __exidx_start = .;
  *(.ARM.exidx*)
  __exidx_end = .;
 } >rom
 . = ALIGN(4);
 _etext = .;
 .noinit (NOLOAD) : {
  *(.noinit*)
 } >ram
 . = ALIGN(4);
 .data : {
  _data = .;
  *(.data*)
  *(.ramtext*)
  . = ALIGN(4);
  _edata = .;
 } >ram AT >rom
 _data_loadaddr = LOADADDR(.data);
 .bss : {
  *(.bss*)
  *(COMMON)
  . = ALIGN(4);
  _ebss = .;
 } >ram
 /DISCARD/ : { *(.eh_frame) }
 . = ALIGN(4);
 end = .;
}
PROVIDE(_stack = ORIGIN(ram) + LENGTH(ram));
