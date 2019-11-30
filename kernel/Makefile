KERNEL_FLAGS := $(KERNEL_FLAGS) -Iinclude

.PHONY: all

all: String.o Video.o Terminal.o Kernel.o
	cp *.o ../build

String.o:
	$(CPP) -c String.cpp -o String.o $(KERNEL_FLAGS)
	
Video.o:
	$(CPP) -c Video.cpp -o Video.o $(KERNEL_FLAGS)
	
Terminal.o:
	$(CPP) -c Terminal.cpp -o Terminal.o $(KERNEL_FLAGS)
	
Kernel.o:
	$(CPP) -c Kernel.cpp -o Kernel.o $(KERNEL_FLAGS) 
	
clean:
	rm -rf *.o
	