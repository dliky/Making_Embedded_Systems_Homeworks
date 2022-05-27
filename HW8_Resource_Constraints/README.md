# Resource Constraints
 
Compile your project code so it prints out the heap pointer and the stack pointer. Also, print out
addresses to:
* An initialized global variable
* An uninitialized global variable
* A static variable inside a function
* A variable inside a function
Do these variables seem like they are in sensible places given the map file?
If you can find it, modify your linker file to swap your uninitialized variables and initialized
variables. Verify it is as expected in the memory map. See how that changes your code output.

## Printing resource constraints

To get the info, I wrote a small program for a STM32L476RG board compiled with STM32CubeIDE.
```c
/* USER CODE BEGIN PV */
int global_init = 1;
int global_uninit;
/* USER CODE END PV */
.
.
.
void memVar(void)
{
	static int static_func_var = 0;
	int func_var = 10;
	volatile uint32_t* heap_addr_1 = malloc(16);
	volatile uint32_t* heap_addr_2 = malloc(5*sizeof(uint32_t));

	printf("static function var: %p\r\n", &static_func_var);
	printf("function var: %p\r\n", &func_var);
}
.
.
.
 while (1)
  {
	  	extern uint8_t _end; /* Symbol defined in the linker script */
	    extern uint8_t _estack; /* Symbol defined in the linker script */
	    printf("Stack pointer: %p\r\n", &_estack);
	    printf("Heap pointer: %p\r\n", &_end);
	    printf("Initialized global var pointer: %p\r\n", &global_init);
	    printf("Uninitialized global var pointer: %p\r\n", &global_uninit);

	    memVar();


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
```
## Printouts from CubeIDE
<<<<<<< HEAD
![Expressions](https://github.com/dliky/Making_Embedded_Systems_Homeworks/blob/master/HW8_Resource_Constraints/images/expressions.png)
=======
![expressions](https://github.com/dliky/Making_Embedded_Systems_Homeworks/blob/master/HW8_Resource_Constraints/images/expressions.png)
>>>>>>> 82f139aee97e1afcbcd2324ec0fb6fae1be59ec4

## Memory Usage and Addresses
![memory_usage](https://github.com/dliky/Making_Embedded_Systems_Homeworks/blob/master/HW8_Resource_Constraints/images/memory_usage.png)

## Stack Pointer
![stack_pointer](https://github.com/dliky/Making_Embedded_Systems_Homeworks/blob/master/HW8_Resource_Constraints/images/stack_pointer.png)

### Memory Sections (found in the linker script auto-generated file)
```
/* Constant data into "FLASH" Rom type memory */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

 /* Initialized data sections into "RAM" Ram type memory */
  .data :
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */
    *(.RamFunc)        /* .RamFunc sections */
    *(.RamFunc*)       /* .RamFunc* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */

  } >RAM AT> FLASH

  /* Uninitialized data section into "RAM" Ram type memory */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM

  /* User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM
```








