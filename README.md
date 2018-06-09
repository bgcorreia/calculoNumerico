# Numeric Calcule - Infrastructure

## Containers

- *Webserver* - Nginx;
- *Letsencrypt* - Nginx;
- *Backend PHP* - PHP-fpm;

3 Containers.

## Infrastructure

![Infrastructure Pipa](build/images/infra-pipa.png)

## Requisites

- Docker version 17.09.1-ce or above (https://docs.docker.com/install/)
- Docker Compose 1.20.1 or above (https://docs.docker.com/compose/install)

## Installation

Clone the repository recursively with:
```
user@host:~# git clone --recurse-submodules https://github.com/bgcorreia/calculonumerico.git
```
This mode the repositorys the frontend and backend are cloned.


## Pre-Execution

Create file `.env` in root directory on repository informing enviremont variables, example content:

```bash
user@host:~/calculonumerico# cat .env
APPS_NUMBER=1
APPNAME1=pipa
DOMAIN1=com.br
EMAIL_LETS=lets@domain.com
DB_HOST=pipa_db
DB_NAME=pipa
DB_USER=user
DB_PASS=123
FQDN=www.pipa.com.br
DOMAIN=pipa.com.br
SMTP_SERVER=smtp.gmail.com
SMTP_PORT=587
EMAIL_USER=user@gmail.com
EMAIL_PASS=password
WEBMASTER=PIPA.COM.BR
```

## Execution

In the root repository, execute the next command:

```bash
user@host:~/pipa# docker-compose up -d
```
The option `-d` execute containers in background.

## SSL

Per default, the first execution use no-ssl. Case need use ssl, after execution (with containers running), do following:

```
user@host:~/pipa# docker exec letsencrypt  bash -c 'certbot certonly --email ${EMAIL_LETS} -a webroot --webroot-path=/usr/share/nginx/html -d ${FQDN} -d ${DOMAIN} --agree-tos'
```

OBS.: Use option -d according with need.

After, in projecty directory:

```
user@host:~/pipa# docker-compose restart proxy_pipa
Restarting proxy ... done
```

Enjoy!

