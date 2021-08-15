echo "Running the docker buildenv image"
sudo docker run -d --name="neo-buildenv" --rm -it -v "$(pwd):/root/env" neo-buildenv
echo "Compiling all the sources"
sudo docker exec neo-buildenv make build-i686
echo "Stopping the docker container"
sudo docker stop neo-buildenv