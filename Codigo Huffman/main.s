	.file	"main.c"
	.section .rdata,"dr"
.LC0:
	.ascii "%c %d\12\0"
	.align 8
.LC1:
	.ascii "No hay mas memoria disponible, archivo demasiado grande\0"
	.text
	.globl	leerArchivo
	.def	leerArchivo;	.scl	2;	.type	32;	.endef
	.seh_proc	leerArchivo
leerArchivo:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	leaq	-32(%rbp), %rcx
	leaq	-25(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	fscanf
	jmp	.L2
.L12:
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	$0, -16(%rbp)
	movl	$40, %ecx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	-32(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%edx, 4(%rax)
	movzbl	-25(%rbp), %edx
	movq	-24(%rbp), %rax
	movb	%dl, (%rax)
	cmpq	$0, -24(%rbp)
	je	.L3
	movq	-24(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 32(%rax)
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	testl	%eax, %eax
	jne	.L5
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	jmp	.L2
.L7:
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L5:
	cmpq	$0, -8(%rbp)
	je	.L6
	movq	-24(%rbp), %rax
	movl	4(%rax), %edx
	movq	-8(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jg	.L7
.L6:
	cmpq	$0, -16(%rbp)
	jne	.L8
	movq	16(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L10
.L8:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L10
.L3:
	leaq	.LC1(%rip), %rcx
	call	printf
	jmp	.L11
.L10:
	leaq	-32(%rbp), %rcx
	leaq	-25(%rbp), %rdx
	movq	24(%rbp), %rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	fscanf
.L2:
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	feof
	testl	%eax, %eax
	je	.L12
.L11:
	nop
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	menorPeso
	.def	menorPeso;	.scl	2;	.type	32;	.endef
	.seh_proc	menorPeso
menorPeso:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	$0, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L16
	movl	$0, %eax
	jmp	.L15
.L18:
	movq	-8(%rbp), %rax
	movl	4(%rax), %edx
	movq	-16(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jl	.L17
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
.L17:
	movq	-16(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L16:
	cmpq	$0, -16(%rbp)
	jne	.L18
	movq	-8(%rbp), %rax
.L15:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "Memoria insuficiente para crear los nodos...\0"
	.text
	.globl	crearArbol
	.def	crearArbol;	.scl	2;	.type	32;	.endef
	.seh_proc	crearArbol
crearArbol:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -40(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L22
	movl	$0, %eax
	jmp	.L21
.L30:
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	call	menorPeso
	movq	%rax, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rcx
	call	menorPeso
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L22
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	movl	$40, %ecx
	call	malloc
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.L23
	movq	-48(%rbp), %rax
	movl	4(%rax), %edx
	movq	-8(%rbp), %rax
	movl	4(%rax), %eax
	addl	%eax, %edx
	movq	-16(%rbp), %rax
	movl	%edx, 4(%rax)
	movq	-16(%rbp), %rax
	movb	$0, (%rax)
	movq	-16(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, 24(%rax)
	movq	-48(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 16(%rax)
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 32(%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 16(%rax)
	cmpq	$0, -40(%rbp)
	je	.L22
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	$0, -32(%rbp)
	jmp	.L25
.L27:
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L25:
	cmpq	$0, -24(%rbp)
	je	.L26
	movq	-16(%rbp), %rax
	movl	4(%rax), %edx
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	%eax, %edx
	jge	.L27
.L26:
	cmpq	$0, -32(%rbp)
	jne	.L28
	movq	-16(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	.L22
.L28:
	movq	-32(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	jmp	.L22
.L23:
	leaq	.LC2(%rip), %rcx
	call	puts
	movl	$0, %eax
	jmp	.L21
.L22:
	cmpq	$0, -8(%rbp)
	je	.L29
	cmpq	$0, -40(%rbp)
	jne	.L30
.L29:
	movq	-16(%rbp), %rax
.L21:
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "(%c,%d) -> \0"
	.text
	.globl	imprimirLista
	.def	imprimirLista;	.scl	2;	.type	32;	.endef
	.seh_proc	imprimirLista
imprimirLista:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	cmpq	$0, 16(%rbp)
	je	.L34
	movq	16(%rbp), %rax
	movl	4(%rax), %edx
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %rcx
	call	imprimirLista
	nop
	jmp	.L31
.L34:
	nop
.L31:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	invertirCadena
	.def	invertirCadena;	.scl	2;	.type	32;	.endef
	.seh_proc	invertirCadena
invertirCadena:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	-48(%rbp), %rcx
	call	strlen
	subl	$1, %eax
	movl	%eax, -88(%rbp)
	movl	$0, -84(%rbp)
	jmp	.L36
.L37:
	movl	-84(%rbp), %eax
	movslq	%eax, %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -89(%rbp)
	movl	-84(%rbp), %eax
	movslq	%eax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-88(%rbp), %eax
	movslq	%eax, %rcx
	movq	-48(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	movl	-88(%rbp), %eax
	movslq	%eax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-89(%rbp), %eax
	movb	%al, (%rdx)
	subl	$1, -88(%rbp)
	addl	$1, -84(%rbp)
.L36:
	movl	-84(%rbp), %eax
	movslq	%eax, %rbx
	movq	-48(%rbp), %rcx
	call	strlen
	shrq	%rax
	cmpq	%rax, %rbx
	jb	.L37
	movq	-48(%rbp), %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC5:
	.ascii "Letra\11Codigo\0"
	.align 8
.LC6:
	.ascii "Insuficiente memoria, no pudo ser guardado el codigo\0"
.LC7:
	.ascii "%c\11\0"
.LC4:
	.ascii "\0\0"
	.space 28
	.text
	.globl	imprimirHuffman
	.def	imprimirHuffman;	.scl	2;	.type	32;	.endef
	.seh_proc	imprimirHuffman
imprimirHuffman:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	subq	$168, %rsp
	.seh_stackalloc	168
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, 64(%rbp)
	movq	%rdx, 72(%rbp)
	movq	64(%rbp), %rax
	movq	%rax, 24(%rbp)
	movq	$0, -16(%rbp)
	movq	64(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, 16(%rbp)
	movq	64(%rbp), %rax
	movq	%rax, 8(%rbp)
	movzwl	.LC4(%rip), %eax
	movw	%ax, -64(%rbp)
	movq	$0, -62(%rbp)
	movq	$0, -54(%rbp)
	movq	$0, -46(%rbp)
	movl	$0, -38(%rbp)
	movzwl	.LC4(%rip), %eax
	movw	%ax, -96(%rbp)
	movq	$0, -94(%rbp)
	movq	$0, -86(%rbp)
	movq	$0, -78(%rbp)
	movl	$0, -70(%rbp)
	leaq	.LC5(%rip), %rcx
	call	puts
	jmp	.L40
.L51:
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L41
	movl	$40, %ecx
	call	malloc
	movq	%rax, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L42
	leaq	.LC6(%rip), %rcx
	call	puts
.L42:
	movq	24(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-24(%rbp), %rax
	movb	%dl, (%rax)
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$35, %al
	jne	.L43
	movq	-24(%rbp), %rax
	movb	$32, (%rax)
.L43:
	movq	24(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC7(%rip), %rcx
	call	printf
	jmp	.L44
.L47:
	movq	16(%rbp), %rax
	movq	24(%rax), %rax
	cmpq	8(%rbp), %rax
	jne	.L45
	leaq	-64(%rbp), %rax
	movq	$-1, %rcx
	movq	%rax, %rdx
	movl	$0, %eax
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	leaq	-1(%rax), %rdx
	leaq	-64(%rbp), %rax
	addq	%rdx, %rax
	movw	$48, (%rax)
	jmp	.L46
.L45:
	movq	16(%rbp), %rax
	movq	32(%rax), %rax
	cmpq	8(%rbp), %rax
	jne	.L46
	leaq	-64(%rbp), %rax
	movq	$-1, %rcx
	movq	%rax, %rdx
	movl	$0, %eax
	movq	%rdx, %rdi
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	leaq	-1(%rax), %rdx
	leaq	-64(%rbp), %rax
	addq	%rdx, %rax
	movw	$49, (%rax)
.L46:
	movq	16(%rbp), %rax
	movq	%rax, 8(%rbp)
	movq	16(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, 16(%rbp)
.L44:
	cmpq	$0, 16(%rbp)
	jne	.L47
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	invertirCadena
	movq	%rax, %rcx
	call	puts
	movq	-24(%rbp), %rax
	leaq	1(%rax), %rcx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdx
	call	strcpy
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	strcpy
	movq	72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, 0(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L48
.L49:
	movq	0(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	0(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, 0(%rbp)
.L48:
	cmpq	$0, 0(%rbp)
	jne	.L49
	cmpq	$0, -8(%rbp)
	jne	.L50
	movq	72(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	0(%rbp), %rdx
	movq	%rdx, 32(%rax)
	jmp	.L41
.L50:
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 32(%rax)
	movq	-24(%rbp), %rax
	movq	0(%rbp), %rdx
	movq	%rdx, 32(%rax)
.L41:
	movq	24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, 24(%rbp)
	cmpq	$0, 24(%rbp)
	je	.L40
	movq	24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, 16(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, 8(%rbp)
.L40:
	cmpq	$0, 24(%rbp)
	jne	.L51
	nop
	addq	$168, %rsp
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC8:
	.ascii "ERROR FATAL! el simbolo buscado no existe en los registros\0"
.LC9:
	.ascii "CODIFICACION TERMINADA!\0"
	.text
	.globl	codificarHuffman
	.def	codificarHuffman;	.scl	2;	.type	32;	.endef
	.seh_proc	codificarHuffman
codificarHuffman:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	16(%rbp), %rcx
	call	strlen
	movl	%eax, -20(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L53
.L59:
	movq	32(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	$0, -32(%rbp)
	jmp	.L54
.L56:
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-16(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -16(%rbp)
.L54:
	cmpq	$0, -16(%rbp)
	je	.L55
	movq	-16(%rbp), %rax
	movzbl	(%rax), %edx
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movq	16(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L56
.L55:
	cmpq	$0, -16(%rbp)
	jne	.L57
	leaq	.LC8(%rip), %rcx
	call	puts
	jmp	.L52
.L57:
	movq	-16(%rbp), %rax
	leaq	1(%rax), %rdx
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	strcat
	addl	$1, -4(%rbp)
.L53:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	cmpl	-4(%rbp), %eax
	jg	.L59
	leaq	.LC9(%rip), %rcx
	call	puts
	nop
.L52:
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC10:
	.ascii "\12DECODIFICACION TERMINADA!\0"
	.text
	.globl	decodificarHuffman
	.def	decodificarHuffman;	.scl	2;	.type	32;	.endef
	.seh_proc	decodificarHuffman
decodificarHuffman:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rcx
	call	strlen
	movl	%eax, -20(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L61
.L67:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L62
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$35, %al
	jne	.L63
	movl	$32, %ecx
	call	putchar
	jmp	.L64
.L63:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	putchar
.L64:
	movq	24(%rbp), %rax
	movq	%rax, -16(%rbp)
.L62:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$48, %al
	jne	.L65
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L66
.L65:
	movq	-16(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -16(%rbp)
.L66:
	addl	$1, -4(%rbp)
.L61:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jle	.L67
	leaq	.LC10(%rip), %rcx
	call	puts
	nop
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC11:
	.ascii "Bienvenido a Codigo Huffman\0"
.LC12:
	.ascii "r\0"
.LC13:
	.ascii "abecedariocompleto.txt\0"
.LC14:
	.ascii "No hay archivo de abecedario\0"
	.align 8
.LC15:
	.ascii "Codificacion creada correctamente.\0"
.LC16:
	.ascii "Ingrese texto a codificar:\0"
	.align 8
.LC17:
	.ascii "El tama\303\261o del texto en bits es: %d\12\12\0"
	.align 8
.LC19:
	.ascii "\12\12El nuevo tama\303\261o en bits es de: %d y se comprimio un %.2f%%\0"
.LC20:
	.ascii "\12Decodificando...\0"
	.align 8
.LC21:
	.ascii "\12Programa finalizado! (0 para terminar)\0"
.LC22:
	.ascii "%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	subq	$1464, %rsp
	.seh_stackalloc	1464
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, 1360(%rbp)
	movq	%rdx, 1368(%rbp)
	call	__main
	movq	$0, 1296(%rbp)
	movq	$0, 1320(%rbp)
	movq	$0, 1288(%rbp)
	leaq	1136(%rbp), %rdx
	movl	$0, %eax
	movl	$18, %ecx
	movq	%rdx, %rdi
	rep stosq
	movq	%rdi, %rdx
	movl	%eax, (%rdx)
	addq	$4, %rdx
	movw	%ax, (%rdx)
	addq	$2, %rdx
	leaq	-64(%rbp), %rdx
	movl	$0, %eax
	movl	$150, %ecx
	movq	%rdx, %rdi
	rep stosq
	leaq	.LC11(%rip), %rcx
	call	puts
	leaq	.LC12(%rip), %rdx
	leaq	.LC13(%rip), %rcx
	call	fopen
	movq	%rax, 1312(%rbp)
	cmpq	$0, 1312(%rbp)
	jne	.L69
	leaq	.LC14(%rip), %rcx
	call	printf
	jmp	.L70
.L69:
	movq	1312(%rbp), %rdx
	leaq	1296(%rbp), %rax
	movq	%rax, %rcx
	call	leerArchivo
	movq	1296(%rbp), %rax
	movq	%rax, %rcx
	call	imprimirLista
	movl	$10, %ecx
	call	putchar
	movq	1296(%rbp), %rax
	movq	%rax, %rcx
	call	crearArbol
	movq	%rax, 1320(%rbp)
	movq	1296(%rbp), %rax
	leaq	1288(%rbp), %rdx
	movq	%rax, %rcx
	call	imprimirHuffman
	leaq	.LC15(%rip), %rcx
	call	puts
	leaq	.LC16(%rip), %rcx
	call	puts
	movq	__imp___iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %rdx
	leaq	1136(%rbp), %rax
	movq	%rdx, %r8
	movl	$104, %edx
	movq	%rax, %rcx
	call	fgets
	leaq	1136(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	sall	$3, %eax
	movl	%eax, 1308(%rbp)
	movl	1308(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC17(%rip), %rcx
	call	printf
	movq	1288(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	leaq	1136(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	codificarHuffman
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	puts
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	movl	%eax, 1304(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2sd	1304(%rbp), %xmm0
	movsd	.LC18(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sd	1308(%rbp), %xmm1
	divsd	%xmm1, %xmm0
	movsd	.LC18(%rip), %xmm1
	subsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rdx, -88(%rbp)
	movsd	-88(%rbp), %xmm1
	movq	%rax, -88(%rbp)
	movsd	-88(%rbp), %xmm0
	movl	1304(%rbp), %eax
	movapd	%xmm1, %xmm2
	movq	%xmm0, %r8
	movl	%eax, %edx
	leaq	.LC19(%rip), %rcx
	call	printf
	leaq	.LC20(%rip), %rcx
	call	puts
	movq	1320(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	decodificarHuffman
	leaq	.LC21(%rip), %rcx
	call	puts
	movl	$1, -68(%rbp)
	leaq	-68(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC22(%rip), %rcx
	call	scanf
	jmp	.L71
.L72:
	leaq	.LC21(%rip), %rcx
	call	puts
	leaq	-68(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC22(%rip), %rcx
	call	scanf
.L71:
	movl	-68(%rbp), %eax
	testl	%eax, %eax
	jne	.L72
.L70:
	movl	$0, %eax
	addq	$1464, %rsp
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC18:
	.long	0
	.long	1079574528
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	fscanf;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	feof;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef
	.def	strcat;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
