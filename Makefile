COMPILER = gcc
C_OPT = -c 

a.out: main.o employeeList.o employee.o tools.o  costumerList.o costumer.o system.o
	$(COMPILER) main.o employeeList.o employee.o tools.o costumerList.o costumer.o system.o
main.o: main.c
	$(COMPILER) $(C_OPT) main.c

employeeList.o: employeeList.c
	$(COMPILER) $(C_OPT) employeeList.c

employee.o: employee.c
	$(COMPILER) $(C_OPT) employee.c

tools.o: tools.c
	$(COMPILER) $(C_OPT) tools.c

costumerList.o: costumerList.c
	$(COMPILER) $(C_OPT) costumerList.c

costumer.o: costumer.c
	$(COMPILER) $(C_OPT) costumer.c

system.o: system.c
	$(COMPILER) $(C_OPT) system.c

clean :
	rm -f *.o

