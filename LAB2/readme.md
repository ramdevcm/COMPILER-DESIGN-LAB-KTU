STEPS TO REPRODUCE

install lex on your machine

sudo apt install flex

sudo apt install bison


root@kali:~/Desktop/cdlab/COMPILER-DESIGN-LAB-KTU/LAB2# lex first.l 
root@kali:~/Desktop/cdlab/COMPILER-DESIGN-LAB-KTU/LAB2# gcc -lfl lex.yy.c 
root@kali:~/Desktop/cdlab/COMPILER-DESIGN-LAB-KTU/LAB2# ./a.out 