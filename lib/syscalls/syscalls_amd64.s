
.global sys_exit
sys_exit:
	mov $1, %rax
	syscall

.global sys_read
sys_read:
	mov $3, %rax
	syscall
	jc 1f
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFFFFFFFFFF, %eax
	ret

.global sys_write
sys_write:
	mov $4, %rax
	syscall
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFFFFFFFFFF, %eax
	ret

.global sys_open
sys_open:
	mov $5, %rax
	syscall
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFFFFFFFFFF, %eax
	ret

.global sys_close
sys_close:
	mov $6, %rax
	syscall
	ret

	1:
	mov %eax, errno
	mov $0xFFFFFFFFFFFFFFFF, %eax
	ret

