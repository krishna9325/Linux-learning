Let us suppose we have 2 c files add.c and sub.c. Both files functions are getting invoked in calc.c. We want to provide the dynamic linking, then follow below steps:

Step 1:
First get the .o files for add.c, sub.c and calc.c :
	Command:- gcc -c add.c -o add.o (Compile and assemble to .o file)
		  gcc -c sub.c -o sub.o
		  gcc -c calc.c -o calc.o


step 2: (Load)
Now create .so file :
	Command:- gcc -shared -o lib_calc.so add.o sub.o (Load .o files to lib_calc.so) 
	

step 3: (Linking)
Link .so file to the obj file :
	Command: gcc -o dynamic_exe calc.o -L. lib_calc.so (Link lib_calc.so to executable file)
	
step 4: 
Export the lib_calc.so path (otherwise executable file will not identify the location) :
	Command: export LD_LIBRARY_PATH = .:$LD_LIBRARY_PATH
	
step 5:
Execute the dynamic_exe file to get output
	Command: ./dynamic_exe
	



