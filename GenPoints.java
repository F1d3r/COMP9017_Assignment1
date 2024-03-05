//import java.text.DecimalFormat;

public class GenPoints{


    public static void main(String[] args){
        System.out.println(args.length);

        int numberOfPoints = 10;
        //int numberOfPoints = Integer.parseInt(args[1]);    // Number of Points.
        // Range of points coordinate.
        double minX = -50;
        double maxX = 50;
        double minY = -50;
        double maxY = 50;
        double minDistance = 1;
        //double minDistance = Integer.parseInt(args[0]);  // Minumu distance to other points.
        double[][] points = new double[numberOfPoints][2];    // Used to store points.
        //DecimalFormat format = new DecimalFormat("#.00");   // For print format

        
        // Generate the first point.
        double x = generateRandom(minX, maxY);
        double y = generateRandom(minY, maxY);
        
        // Store the point into the array.
        points[0][0] = x;
        points[0][1] = y;

        // Generate the x and y coordinate for the rest of points.
        for(int i = 1; i < numberOfPoints; i++){
            boolean valid = false;
            // Check if the generated point valid.
            while(!valid){
                x = generateRandom(minX, maxY);
                y = generateRandom(minY, maxY);
                // Calculate the distance to existed points.
                for(int j = 0; j < i; j++){
                    double dis = Math.sqrt(Math.pow((points[j][0] - x), 2) + Math.pow((points[j][1] - y), 2));
                    // If it is too close to some point.
                    if(dis <= minDistance){
                        valid = false;
                        System.out.println("Too close! Invalid!");
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
            System.out.printf("%.2f\n", (points[i][0]));
        }

        /*
        for(int i = 0; i < numberOfPoints; i++){
            System.out.println(format.format(points[i][0]) + ", " + format.format(points[i][0]));
        }
        */
    }




    private static double generateRandom(double min, double max){
        return (min + Math.random() * (max - min));
    }


}