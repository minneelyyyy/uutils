
.global sys_write
sys_write:
	mov $4, %rax
	syscall
	ret

.global sys_exit
sys_exit:
	mov $1, %rax
	syscall


.global sys_fcntl
sys_fcntl:
	mov $92, %rax
	syscall
	ret

