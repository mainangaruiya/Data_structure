public class Main {
    public static void main(String[] args) {
        int[] score = {86, 68, 74, 90, 51, 70, 80, 60, 84};
        int sum = 0;
        int mean;

        for (int i = 0; i < 9; i++) {
            sum += score[i];
        }

        mean = sum / 9;

        System.out.println("The sum is " + sum);
        System.out.println("The mean score is " + mean);
    }
}

