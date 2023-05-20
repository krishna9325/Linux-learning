Let us suppose we have 2 c files add.c and sub.c. Both files functions are getting invoked in calc.c. We want to provide the static linking, then follow below steps:

Step 1:
First get the .o files for add.c, sub.c and calc.c :
	Command:- gcc -c add.c -o add.o (Compile and assemble to .o file)
		  gcc -c sub.c -o sub.o
		  gcc -c calc.c -o calc.o


step 2: (Load)
Now create .so file :
	Command:- ar rcs lib_calc.a add.o sub.o(Load .o files to lib_calc.a) 
	

step 3: (Linking)
Link .so file to the obj file :
	Command: gcc -o static_exe calc.o -L. lib_calc.a (Link lib_calc.a to executable file)
	
step 4: 
Execute the dynamic_exe file to get output
	Command: ./static_exe
	



