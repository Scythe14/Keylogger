KERNEL_VERSION	=	$(shell uname -r)

SRC		=	keylog.c
OBJ		=	$(SRC:.c=.o)

obj-m		+=	keylog.o

keylogger-objs	:=	$(OBJ)


all:
	make -C /lib/modules/$(KERNEL_VERSION)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(KERNEL_VERSION)/build M=$(PWD) clean
