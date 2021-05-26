section .text
	global _ft_strcmp

_ft_strcmp:
	mov rax, 0
	mov rdx, 0
	mov rcx, 0
	mov al, BYTE [rsi + rcx]
	cmp BYTE [rdi + rcx], al
	je com
	jne end

com:
	inc rcx
	mov al, BYTE [rsi + rcx]
	cmp BYTE [rdi + rcx], 0
	je end
	cmp BYTE [rsi + rcx], 0
	je end
	cmp BYTE [rdi + rcx], al
	je com
	jne end


end:
	mov al, [rdi + rcx]
	mov dl, [rsi + rcx]
	sub rax, rdx
	ret
