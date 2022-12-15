.extern errno

.global sys_exit
sys_exit:
	mov $1, %rax
	syscall

.macro define_syscall name,num
.global \name
\name:
	mov $\num, %rax
	syscall
	jc 1f
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFFFFFFFFFF, %eax
	ret
.endm

DEFINE_SYSCALL sys_read,2
DEFINE_SYSCALL sys_write,3
DEFINE_SYSCALL sys_open,4
DEFINE_SYSCALL sys_close,5
