#!/bin/bash

RunningProcess() {
    ps aux
}

SearchProcess() {
    ps aux | grep "$1"
}

KillProcess() {
    if [ -d "/proc/$1" ]; then
        echo "Killing Process $1"
        kill "$1"
    else
        echo "Process with PID $1 is not running"
    fi
}

SystemResource() {
    df -h
}

while true; do
    echo -e "Enter Operation: Kill process (kill) / Search process (search) / Check Current Running Processes (current) / Check System Resources (res) / Exit (exit)"
    read user

    case "$user" in
        "kill")
            read -p "Enter PID to kill: " pid
            KillProcess "$pid"
            ;;
        "search")
            read -p "Enter Process Name: " pname
            SearchProcess "$pname"
            ;;
        "current")
            RunningProcess
            ;;
        "res")
            SystemResource
            ;;
        "exit")
            break
            ;;
        *)
            echo "Invalid option! Please try again."
            ;;
    esac
done

