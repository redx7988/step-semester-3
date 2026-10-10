import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

interface Question {
    int evaluate(String answer);
    String getId();
}

class MCQ implements Question {
    private String id;
    private String correctAnswer;
    public MCQ(String id, String correct) { this.id = id; this.correctAnswer = correct; }
    public int evaluate(String answer) { return answer.equalsIgnoreCase(correctAnswer) ? 5 : 0; }
    public String getId() { return id; }
}

class TrueFalseQuestion implements Question {
    private String id;
    private String correctAnswer;
    public TrueFalseQuestion(String id, String correct) { this.id = id; this.correctAnswer = correct; }
    public int evaluate(String answer) { return answer.equalsIgnoreCase(correctAnswer) ? 5 : 0; }
    public String getId() { return id; }
}

class Attempt {
    private String studentId;
    private String examId;
    private Map<String, String> answers = new HashMap<>();
    private boolean submitted = false;

    public Attempt(String studentId, String examId) {
        this.studentId = studentId;
        this.examId = examId;
        System.out.println(examId + " started by " + studentId + ".");
    }

    public void recordAnswer(String questionId, String answer) {
        if (submitted) {
            System.out.println("Cannot change answers for a submitted examination.");
            return;
        }
        answers.put(questionId, answer);
        System.out.println("Answer recorded for " + questionId + ".");
    }

    public void submit(List<Question> questions) {
        submitted = true;
        System.out.println(examId + " submitted by " + studentId + ". Result:");
        int total = 0;
        int maxTotal = questions.size() * 5;
        for (Question q : questions) {
            String ans = answers.getOrDefault(q.getId(), "");
            int score = q.evaluate(ans);
            total += score;
            System.out.print(q.getId() + ": " + (score > 0 ? "Correct" : "Incorrect") + " (" + score + " points), ");
        }
        System.out.println("\nTotal score: " + total + "/" + maxTotal + ".");
    }
}

public class Q3 {
    public static void main(String[] args) {
        List<Question> examQuestions = new ArrayList<>();
        examQuestions.add(new MCQ("Question 1", "C"));
        examQuestions.add(new TrueFalseQuestion("Question 2", "True"));

        // Sample Input Execution
        Attempt attempt = new Attempt("Student 1", "Exam A");
        attempt.recordAnswer("Question 1", "C");
        attempt.recordAnswer("Question 2", "True");
        attempt.submit(examQuestions);
        attempt.recordAnswer("Question 1", "B");
    }
}