all:	lab16

lab16:	cscd240Lab16.c ./linkedList/linkedList.c ./listUtils/listUtils.c ./utils/utils.c ./utils/fileUtils.c ./words/word.c
	gcc -m32 -o lab16 cscd240Lab16.c ./linkedList/linkedList.c ./listUtils/listUtils.c ./utils/fileUtils.c ./utils/utils.c ./words/word.c
   
   
clean:
	rm lab16
   
