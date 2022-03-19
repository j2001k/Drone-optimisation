while (!deliveries.empty())
{
    //pick the delivery which we have to do first
    delivery t = deliveries1.front();
    //deliveries 1 has list of deliveries sorted according to time according to time

    //for each warehouse we also have deliveries sorted according to their time stamp in delware[i] for ith warehouse

    //pick the first drone that can do this delivery on time
    drone selected;//selected drone
    ware wh;//ware housee from which the drone starts
    for (int i = 0; i < 5; i++) //6 drones are there
    {
        if (drone[i].can(t)) //if(drone i can do the delivery t in its time) starting form rest and full energy
        {
            selected = drone[i];
            selected.assign(t);//assign this delivery to selected drone
            deliveries.pop_front();
            wh = t.wh(); //the ware house frm which the drone starts
            delware[wh].erase(t);//erasing the delivery as it is assigned
            break;
        }
    }

    //now assign as many deliveries to selected drone as you can for the same warehouse
    //taking in acount the number of slots in drone
    //also the deliveries should be on the same day as the first delivery
    for (auto i : delware[wh])
    {
        if (selected.can(i))
        {
            //assign this delivery to selected drone
            selected.assign(i);
            deliveries.erase(i);
            delware[wh].erase(i);
            //from this we can calculate the resting time of drone as well
        }
    }
    //drone class data members
    // 1.time
    // 2.energy
    // 3.path(with time stamps)

    // in assign method for a drone the following changes takes place
    // 1.upto 3 mins of its arrival at the delivery(passed as a parameter) it is "booked"
    // 2.energy changes takes place
    // 3.path is added to the delivery point also considering the no-fly zones

    //now the return path
    //we simply return the rone to closest warehouse
    selected.returned();

    dronelist.pb(selected);//dronelist is the list of drones that we have to fly at last
    //and every drone has its path encapsulated in it
}
