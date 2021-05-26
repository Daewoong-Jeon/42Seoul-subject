FROM debian:buster

LABEL maintainer="djeon@student.42seoul.kr"

RUN apt-get update
RUN apt-get -y install nginx curl			# install nginx
RUN apt-get -y install openssl				# install openssl
RUN apt-get -y install vim					# install vim
RUN apt-get -y install php-fpm				# install php-fpm
RUN apt-get -y install mariadb-server php-mysql php-mbstring	# install MariaDB
RUN apt-get -y install php-curl
RUN apt-get -y install wget					# install phpMyAdmin, wordpress

COPY ./srcs/server .
COPY ./srcs/run.sh .
COPY ./srcs/config.inc.php .
COPY ./srcs/wp-config.php .

CMD bash run.sh
