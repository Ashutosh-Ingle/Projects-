import java.util.*;

enum MathOperation
{
    ADD('+'),                // ADD value is an instance of mathoperatiom enum
    SUBTRACT('-'),              //Enum types are classes
    MULTIPLY('*'),              //Values are ordered
    DIVIDE('/');

    private char symbol;        //hold the symbol for each value
    public char getSymbol()     //store the symbol and get access
    {
        return symbol;
    }
    private MathOperation(char symbol)  //specify symbol
    {
        this.symbol = symbol;           
    }
}
class MathEquation
{
    private double leftVal;
    private double rightVal;
    private MathOperation opCode;
    private double result;

    private static int numberOfCalculations;
    private static double sumOfResults;


    public MathEquation()
    {}

    public MathEquation(MathOperation opCode)
    {
        this.opCode = opCode;
    }
    public MathEquation(MathOperation opCode, double leftVal, double rightVal)
    {
        this(opCode);
        this.leftVal = leftVal;
        this.rightVal = rightVal;
    }

    public double getResult()
    {
        return result;
    }

    public void setLeftVal(double leftVal)
    {
        this.leftVal = leftVal;
    }

    public double getLeftVal()
    {
        return leftVal;
    }

    public void setRightVal(double rightVal)
    {
        this.rightVal = rightVal;
    }
    
    public double getRightVal()
    {
        return rightVal;
    }

    public void setOpCode(MathOperation opCode)
    {
        this.opCode = opCode;
    }

    public MathOperation getOpCode()
    {
        return opCode;
    }

    public void execute()
    {
        switch(opCode)
        {
            case ADD:
                result = leftVal + rightVal;
                break;
            
            case SUBTRACT:
                result = leftVal - rightVal;
                break;

            case MULTIPLY:
                result = leftVal * rightVal;
                break;

            case DIVIDE:
                result = rightVal != 0 ? leftVal / rightVal : 0.0d;
                break;
            default:
                System.out.println("Invalid opcode: "+ opCode);
                result = 0.0d;
                break;
        }
        numberOfCalculations++;
        sumOfResults = sumOfResults +result;
        
    }

    public void execute(double leftVal, double rightVal)
    {
        this.leftVal = leftVal;
        this.rightVal = rightVal;
        execute();
    }

    public void execute(int leftVal,int rightVal)
    {
        this.leftVal = leftVal;
        this.rightVal = rightVal;
        execute();

        result = (int)result;
    }

    public static double getAverageResult()
    {
        return sumOfResults/numberOfCalculations;
    }

    @Override
    public String toString()
    {
        char symbol = opCode.getSymbol();

        StringBuilder builder = new StringBuilder(20);
        builder.append(leftVal);
        builder.append(" ");
        builder.append(symbol);
        builder.append(" ");
        builder.append(rightVal);
        builder.append(" = ");
        builder.append(result);

        return builder.toString();
    }
}

class CalcEngineProject
{
    public static void main(String arg[])
    {
        if(arg.length == 0)
        { 
            performCalculations();
        }
        else if(arg.length == 3)
        {
            performOperation(arg);
        }
        else if(arg.length == 1 && arg[0].equals("interactive"))
        {
            executeInteractively();
        }
        else
        {
            System.out.println("Please provide an operation code and 2 numeric values");
        }
    }

    static void performCalculations()
    {
        MathEquation[] equations = new MathEquation[4];
        equations[0] = new MathEquation(MathOperation.DIVIDE,100.0d,50.0d);
        equations[1] = new MathEquation(MathOperation.ADD,25.0d, 92.0d);
        equations[2] = new MathEquation(MathOperation.SUBTRACT,225.0d, 17.0d);
        equations[3] = new MathEquation(MathOperation.MULTIPLY,11.0d, 3.0d);
        
        for(MathEquation equation : equations)
        {
            equation.execute();
            System.out.println(equation);       //println will call toString method
        }
        System.out.println("Average results = "+ MathEquation.getAverageResult());

        //useOverloads()    
       }

    static void useOverloads()
    {
         System.out.println();
        System.out.println("using execute overloads");
        System.out.println();
        
        MathEquation equationOverload = new MathEquation(MathOperation.DIVIDE);
        double leftVal = 9.0d;
        double rightVal = 4.0d;
        equationOverload.execute(leftVal,rightVal);
        System.out.println("Overload result with double : "+ equationOverload.getResult());

        int leftInt = 9;
        int rightInt = 4;
        equationOverload.execute(leftInt,rightInt);
        System.out.println("Overload result with ints : "+ equationOverload.getResult());    
    }

    static void executeInteractively()
    {
        System.out.println("Enter an operation and two numbers");
        Scanner sobj = new Scanner(System.in);
        String userInput = sobj.nextLine();
        String[] parts = userInput.split(" ");
        performOperation(parts);
    }
    
    private static void performOperation(String[] parts)
    {
        MathOperation opCode = MathOperation.valueOf(parts[0].toUpperCase());
        double leftVal = valueFromWord(parts[1]);
        double rightVal = valueFromWord(parts[2]);

        MathEquation equation = new MathEquation(opCode,leftVal,rightVal);
        equation.execute();
        System.out.println(equation);
    }

    static double valueFromWord(String word)
    {
        String[] numberWords = {"zero", "one","two", "three","four","five","six","seven","eight","nine"};
        double value = 0.0d;

        boolean isValueSet = false;
        
        for(int index = 0; index < numberWords.length;index++)
        {
            if(word.equals(numberWords[index]))
            {
                value = index;

                isValueSet = true;
                break;
            }
        }
        if(!isValueSet)
        {
            value = Double.parseDouble(word);
        }
        return value;
    }
}