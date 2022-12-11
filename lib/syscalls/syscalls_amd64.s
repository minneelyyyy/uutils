
.global sys_exit
sys_exit:
	mov $1, %rax
	syscall

.global sys_read
sys_read:
	mov $3, %rax
	syscall
	ret

.global sys_write
sys_write:
	mov $4, %rax
	syscall
	ret

.global sys_open
sys_open:
	mov $5, %rax
	syscall
	ret

.global sys_close
sys_close:
	mov $6, %rax
	syscall
	ret

.global sys_fcntl
sys_fcntl:
	mov $92, %rax
	syscall
	ret
