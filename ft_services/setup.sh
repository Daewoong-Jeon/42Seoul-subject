# minikube reset
minikube stop
minikube delete
minikube start --driver=virtualbox
minikube status

# minikube ip env setup
MINIKUBE_IP=$(minikube ip)

# pull minikube docker CLI
eval $(minikube -p minikube docker-env)

echo "metalLB setup start"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
sed "s/MINIKUBE_IP/$MINIKUBE_IP/g" srcs/metallb-config_format.yaml > srcs/metallb-config.yaml
kubectl apply -f srcs/metallb-config.yaml

echo "build image"
docker build -t alpine-nginx srcs/nginx/
docker build -t alpine-mysql srcs/mysql/
docker build -t alpine-wordpress srcs/wordpress/
docker build -t alpine-phpmyadmin srcs/phpmyadmin/
docker build -t alpine-influxdb srcs/influxdb/
docker build -t alpine-grafana srcs/grafana/
docker build -t alpine-ftps srcs/ftps/

echo "create object"
kubectl apply -f ./srcs/nginx/nginx.yaml
kubectl apply -f ./srcs/mysql/mysql.yaml
kubectl apply -f ./srcs/wordpress/wordpress.yaml
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f ./srcs/influxdb/influxdb.yaml
kubectl apply -f ./srcs/grafana/grafana.yaml
kubectl apply -f ./srcs/ftps/ftps.yaml

kubectl get all
