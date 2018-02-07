$fn = 50;
difference() {
    difference(){
        circle(center=true,r=20);
        square(center=true,[2,1]);
    }
    union(){
        for(i=[0:3]){
            rotate (i*90){
                translate([3,  0]){
                    polygon([[0,0],[14,-7],[14,7]], paths=[[0,1,2]]);
                }
            }
        }
    }
}
