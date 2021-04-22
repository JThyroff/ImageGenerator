//
// Created by Johannes on 21.06.19.
//

#include "FunctionGenerator.h"

struct FunctionGenerator {

    Function *generateTempFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,10);

        char rnd = dist(rng);
        switch (rnd){
            case 0 :
                //255 * !(x & y)
                return new BinFun (new ConstFun(Z),new UnFun(new BinFun(new ConstFun(X),new ConstFun(Y),AND),NEGATE),MUL);
            case 1:
                //x ^ y
                return new BinFun(new ConstFun(X),new ConstFun(Y),XOR);
            case 2:
                //x * ~x -  ~y * y;
                return new BinFun(new BinFun(new ConstFun(X),new UnFun(new ConstFun(X),COMPLEMENT),MUL),new BinFun(new UnFun(new ConstFun(Y),COMPLEMENT),new ConstFun(Y),MUL),MINUS);
            case 3:
                //255 * !(x | y)
                return new BinFun (new ConstFun(Z),new UnFun(new BinFun(new ConstFun(X),new ConstFun(Y),OR),NEGATE),MUL);
            case 4:
                //255 * !(x & y) * 255 * ~(x | y)
                return new BinFun(new BinFun (new ConstFun(Z),new UnFun(new BinFun(new ConstFun(X),new ConstFun(Y),AND),NEGATE),MUL),new BinFun (new ConstFun(Z),new UnFun(new BinFun(new ConstFun(X),new ConstFun(Y),OR),COMPLEMENT),MUL),MUL);
            case 5:
                //255 * ~(x | y)
                return new BinFun (new ConstFun(Z),new UnFun(new BinFun(new ConstFun(X),new ConstFun(Y),OR),COMPLEMENT),MUL);
            case 6:
                return new BinFun(generateFunction(2,2,1,1),new ConstFun(W),DIV);
            case 7:
                return new BinFun(generateFunction(2,2,1,1),new ConstFun(H),DIV);
            case 8:
                return new BinFun(new BinFun(new ConstFun(X),new ConstFun(Y),MUL),new ConstFun(H),DIV);
            case 9:
                return new BinFun(new BinFun(new ConstFun(X),new ConstFun(Y),MUL),new ConstFun(W),DIV);
            default:
                return generateFunction(1,1,1,1);
        }
    }

    Function * generateFunction(char probConst, char probUn, char probBin, char TempFin) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,probConst + probUn + probBin + TempFin-1);

        char rnd = dist(rng);
        if (rnd < probConst) {
            return generateConstFunction();
        } else if (rnd >= probConst && rnd < probConst + probUn ) {
            return generateUnaryFunction();
        } else if (rnd >= probConst + probUn && rnd < probConst + probUn + probBin) {
            return generateBinaryFunction();
        }else if(rnd >= probConst + probUn + probBin){
            return generateTempFunction();
        }

    }

    BinFun * generateBinaryFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,6);

        char rnd = dist6(rng);
        switch (rnd) {
            case 0:
                return new BinFun(generateFunction(1, 2, 4, 4), generateFunction(1, 2, 4, 4), PLUS);
            case 1:
                return new BinFun(generateFunction(1, 2, 4, 4), generateFunction(1, 2, 4, 4), MINUS);
            case 2:
                return new BinFun(generateFunction(2, 4, 1, 4), generateFunction(2, 4, 1, 4), MUL);
            case 3:
                return new BinFun(generateFunction(2, 4, 1, 4), generateFunction(2, 4, 1, 4), DIV);
            case 4:
                return new BinFun(generateFunction(2, 4, 1, 4), generateFunction(2, 4, 1, 4), OR);
            case 5:
                return new BinFun(generateFunction(2, 4, 1, 4), generateFunction(2, 4, 1, 4), AND);
            case 6:
                return new BinFun(generateFunction(2, 4, 1, 4), generateFunction(2, 4, 1, 4), XOR);
            default:
                std::cout << "Fehler in FunctionGenerator::generateBinaryFunction()";
                exit(-1);
        }
    }

    UnFun * generateUnaryFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,1);

        char rnd = dist(rng);
        switch (rnd) {
            case 0:
                return new UnFun(generateFunction(2,2,1, 1),NEGATE);
            case 1:
                return new UnFun(generateFunction(2,2,1, 1),COMPLEMENT);
            default:
                std::cout << "Fehler in FunctionGenerator::generateUnaryFunction()";
                exit(-1);
        }
    }

    static ConstFun * generateConstFunction() {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0,6);

        char rnd = dist(rng);
        switch (rnd) {
            case 0:
            case 1:
                return new ConstFun(X);
            case 2:
            case 3:
                return new ConstFun(Y);
            case 4:
                return new ConstFun(Z);
            case 5:
                return new ConstFun(W);
            case 6:
                return new ConstFun(H);
            default:
                std::cout << "Fehler in FunctionGenerator::generateConstFunction()";
                exit(-1);
        }
    }
};