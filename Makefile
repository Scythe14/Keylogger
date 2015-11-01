KERNEL_VERSION	=	$(shell uname -r)

SRC		=	keylog.c
OBJ		=	$(SRC:.c=.o)

obj-m		+=	keylogger.o

keylogger-objs	:=	$(OBJ)


all:
	make -C /lib/modules/3.10.92-1-MANJARO/build M=$(PWD) modules

clean:
	make -C /lib/modules/3.10.92-1-MANJARO/build M=$(PWD) clean
