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
### Printout from CubeIDE









