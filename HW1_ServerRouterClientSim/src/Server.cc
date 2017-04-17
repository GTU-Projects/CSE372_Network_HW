//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include <Server.h>
#include <cstdlib>
#include <cstring>
#include <string>

Define_Module(Server);

using namespace std;

Server::Server() {


}

Server::~Server() {

    // TODO Auto-generated destructor stub
}
void Server::initialize(){
    srand(time(NULL));
    int routerWay;
    nodeNum = par("nodeNum");
    routerNum = par("routerNum");

    cMessage *msg = getRandomNodeMsg(routerWay);

    send(msg, "r_out",routerWay);
    //delete msg;
}

void Server::handleMessage(cMessage *msg){
    int routerWay;

    int counter = par("counter");
    if(counter!=30){
        cMessage *msg1 = getRandomNodeMsg(routerWay);
        send(msg1, "r_out",routerWay);
        --counter;
        par("counter").setLongValue(counter);
    }

    //delete msg;
}

cMessage* Server::getRandomNodeMsg(int &routerWay){
    char nodeInf[50];
    cMessage *msg;
    int nodeID = rand() % (nodeNum*routerNum);
    sprintf(nodeInf,"n%d",nodeID);
    msg = new cMessage(nodeInf);

    routerWay = (nodeID / nodeNum);
    return msg;
}

