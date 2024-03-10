import java.util.Random;
//import java.text.DecimalFormat;

public class GenPoints{

    public static void main(String[] args){
        int numberOfPoints = 1;
        double minDistance = 1;
        int rseed = 0;
        boolean getN = false;
        boolean getMinDistance = false;
        Random random = new Random();


        try{
            // Get the arguments from the command line.
            for(int i = 0; i < args.length; i++){
                String arg = args[i];
                if(arg.startsWith("-N=")){
                    arg = arg.substring(3);
                    int num = Integer.parseInt(arg);
                    if(num < 0){
                        System.err.println("N less than zero");
                        System.exit(-1);
                    }else{
                        numberOfPoints = Integer.parseInt(arg);
                        getN = true;
                    }
                    //System.out.println("Number of points: " + numberOfPoints);
                }else if(arg.startsWith("-mindist=")){
                    arg = arg.substring(9);
                    Double num = Double.parseDouble(arg);
                    if(num < 0 || num > 10){
                        System.err.println("mindist outside range");
                        System.exit(-2);
                    }else{
                        minDistance = Double.parseDouble(arg);
                        getMinDistance = true;
                    }
                    //System.out.println("Minumu distance: " + minDistance);
                }else if(arg.startsWith("-rseed=")){
                    arg = arg.substring(7);
                    rseed = Integer.parseInt(arg);
                    // Set the random with the random seed.
                    random = new Random(rseed);
                    //System.out.println("Rseed: " + rseed);
                }else{
                    // Check if there is an invalid argument given.
                    System.err.println("invalid arguments1");
                    System.exit(-4);
                }
            }
        }
        // Handle other arguments input exception. e.g.: -N=haha; -N= 20.
        catch(Exception e){
            System.err.println("invalid arguments");
            System.exit(-4);
        }
        
        // Check if the two core arguments are given.
        if (!getN || !getMinDistance) {
            System.err.println("invalid arguments");
            System.exit(-4);
        }else{
            if(numberOfPoints > 10000/(Math.PI * Math.pow(minDistance, 2))){
                System.err.println("point saturation");
                System.exit(-3);
            }
        }
        
        
        //int numberOfPoints = Integer.parseInt(args[1]);    // Number of Points.
        //double minDistance = Double.parseDouble(args[2]);  // Minumu distance to other points.
        //DecimalFormat format = new DecimalFormat("#.00");   // For print format
        // Range of points coordinate.
        double minX = -50;
        double maxX = 50;
        double minY = -50;
        double maxY = 50;
        double[][] points = new double[numberOfPoints][2];    // Used to store points.
        
        
        // Generate the first point, because the first point must be valid.
        double x = minX + (maxX - minX) * random.nextDouble();
        double y = minY + (maxY - minY) * random.nextDouble();
        
        // Store the point into the array.
        points[0][0] = x;
        points[0][1] = y;

        // Generate the x and y coordinate for the rest of points.
        for(int i = 1; i < numberOfPoints; i++){
            boolean valid = false;
            // Check if the generated point valid.
            while(!valid){
                x = minX + (maxX - minX) * random.nextDouble();
                y = minY + (maxY - minY) * random.nextDouble();
                // Calculate the distance to existed points.
                for(int j = 0; j < i; j++){
                    double dis = Math.sqrt(Math.pow((points[j][0] - x), 2) + Math.pow((points[j][1] - y), 2));
                    // If it is too close to some point.
                    if(dis < minDistance){
                        valid = false;
                        //System.out.println("Too close! Invalid!");
                        break;
                    }
                    // If the distance is fine and this is the final one point to check.
                    else if(j == i - 1)
                    {
                        valid = true;
                    }
                }
                // The loop is break onece the validation is confirmed true.
            }
            // Store the point into the array.
            points[i][0] = x;
            points[i][1] = y;
        }


        // Print all points.
        for(int i = 0; i < numberOfPoints; i++){
            System.out.printf("%.2f", (points[i][0]));
            System.out.printf(", ");
            System.out.printf("%.2f\n", (points[i][1]));
        }

        //System.out.println(numberOfPoints + " points generated.");

    }

}