#!/bin/bash

gcc -o args print_args.c
if [ "$?" -eq 0 ]
then
    ./args hello 1.5 10 goodbye
fi

echo " "

gcc -o env print_env.c
if [ "$?" -eq 0 ]
then
    ./env
fi