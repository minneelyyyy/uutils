.extern errno

.global sys_exit
sys_exit:
	mov $1, %eax
	int $0x80

.macro define_syscall name, num
.global \name
\name:
	mov $\num, %eax
	int $0x80
	jc 1f
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFF, %eax
	ret
.endm

DEFINE_SYSCALL sys_read,3
DEFINE_SYSCALL sys_write,4
DEFINE_SYSCALL sys_open,5
DEFINE_SYSCALL sys_close,6
