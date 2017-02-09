.text
.globl zfunction
zfunction:

        pushl   %ebp
        movl    %esp, %ebp
        subl    $4, %esp
        movl    $-8372225, %eax
        andl    8(%ebp), %eax 
	movl    %eax,8(%ebp)   
        shll    $4, 8(%ebp)
	movl    8(%ebp),%eax
        leave
        ret
