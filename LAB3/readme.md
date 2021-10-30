**STEPS TO REPRODUCE

install lex and bison on your machine
```
sudo apt install flex
```
```
sudo apt install bison
```

```
ramdev@ramdev:~/COMPILER-DESIGN-LAB-KTU/LAB3$ lex arthexp.l
ramdev@ramdev:~/COMPILER-DESIGN-LAB-KTU/LAB3$ yacc -d arthexp.y
ramdev@ramdev:~/COMPILER-DESIGN-LAB-KTU/LAB3$ gcc lex.yy.c y.tab.c
ramdev@ramdev:~/COMPILER-DESIGN-LAB-KTU/LAB3$ ./a.out 
```

<div align="center">
  <img src="output.png"/> 
</div>
