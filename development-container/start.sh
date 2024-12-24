#!/bin/bash

docker-compose up --build --detach

docker exec -it concurrent-computing bash
