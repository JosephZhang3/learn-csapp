
//store x at 8(%ebp),store y at 12(%ebp)

movl 8(%ebp),%eax
xorl %edx,%edx     //对被除数进行零扩展，将被除数的高32位全置成零。也可以写成  movl $0,%edx
divl 12(%ebp)
movl %eax,4(%esp)  //存放64位被除数的低32位的%eax寄存器，在除法运算结束后暂放32位的商，最后商被写入内存中离栈顶偏移4字节（32位）的位置
movl %edx,(%esp)   //高32位的%edx寄存器，暂放32位的余数，最后余数被写入内存中的栈顶位置
