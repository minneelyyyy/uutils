.extern errno

.global sys_exit
sys_exit:
	mov $1, %eax
	int $0x80

.global sys_read
sys_read:
	mov $3, %eax
	int $0x80
	jc .read_error
	ret

	.read_error:
	mov %eax, errno
	mov $0xFFFFFFFF, %eax
	ret

.global sys_write
sys_write:
	mov $4, %eax
	int $0x80
	jc .write_error
	ret

	.write_error:
	mov %eax, errno
	mov $0xFFFFFFFF, %eax
	ret

.global sys_open
sys_open:
	mov $5, %eax
	int $0x80
	jc .open_error
	ret

	.open_error:
	mov %eax, errno
	mov $0xFFFFFFFF, %eax
	ret

.global sys_close
sys_close:
	mov $6, %eax
	int $0x80
	jc .close_error
	ret

	.close_error:
	mov %eax, errno
	mov $0xFFFFFFFF, %eax
	ret

