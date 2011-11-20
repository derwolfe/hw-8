KUID = CHANGE_ME_TO_YOUR_KUID
LAB_NAME = hash_table

CPP_FLAGS = -DF_SOLUTION

hash_table: main.o Hash_Table.o Bucket.o Linked_List.o PB_entry.o Utility.o
	g++ -g -o hash_table main.o Hash_Table.o Bucket.o Linked_List.o PB_entry.o Utility.o

main.o: Hash_Table.h 
	g++ $(CPP_FLAGS) -c -g main.cpp 

Hash_Table.o: Hash_Table.h Hash_Table.cpp Bucket.h
	g++ $(CPP_FLAGS) -c -g Hash_Table.cpp

Bucket.o: Bucket.h Bucket.cpp Linked_List.h PB_entry.h
	g++ $(CPP_FLAGS) -c -g Bucket.cpp

Linked_List.o: Linked_List.h Linked_List.cpp PB_entry.h
	g++ $(CPP_FLAGS) -c -g Linked_List.cpp

PB_entry.o: PB_entry.h PB_entry.cpp
	g++ $(CPP_FLAGS) -c -g PB_entry.cpp

Utility.o: Utility.h Utility.cpp
	g++ $(CPP_FLAGS) -c -g Utility.cpp

tests: test1 test2 test3 

test1: hash_table
	./hash_table infile_db.txt infile_cmd.txt 10 >output1
	-diff -b -B output1 output1.correct

test2: hash_table
	./hash_table infile_db.txt infile_cmd.txt 20 >output2
	-diff -b -B output2 output2.correct

test3: hash_table
	./hash_table infile_db.txt infile_cmd.txt 30 >output3
	-diff -b -B output3 output3.correct

clean:
	rm -f *.o hash_table core.* *~ output1 output2 output3

tar-file: clean
	@if test -d ../$(KUID)_$(LAB_NAME) ; then \
		( cd .. ; \
		  tar cz $(KUID)_$(LAB_NAME) >$(KUID)_$(LAB_NAME).tar.gz ; \
	  	  echo ""; \
		  echo "**************************************************************"; \
		  echo "The TAR file for you to test and hand in "; \
		  echo "   has been made in the directory above:"; \
		  echo "     " $(KUID)_$(LAB_NAME).tar.gz ; \
		  echo "**************************************************************"; \
		) ; \
	else \
		( echo "*** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ***"; \
		  echo "The <your KUID>_<lab-name> directory was not found. "; \
		  echo "Remember that you should rename the "; \
		  echo "\"starter-code\" directory created by the "; \
		  echo "starter TAR file and set the KUID " ; \
		  echo "variable in the Makefile"; \
		) ; \
	fi
