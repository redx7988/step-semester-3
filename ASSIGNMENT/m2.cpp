public abstract class ArtPiece {
    private static int counter = 1;
    protected final int pieceId;

    public ArtPiece() {
        this.pieceId = counter++;
    }

    public abstract String describe();

    public String getPieceId() {
        return String.valueOf(pieceId);
    }
}

public class Painting extends ArtPiece {
    private String title;

    public Painting(String title) {
        super();
        this.title = title;
    }

    @Override
    public String describe() {
        return "Painting: " + title + ", framed on canvas";
    }
}

public class Sculpture extends ArtPiece {
    private String title;

    public Sculpture(String title) {
        super();
        this.title = title;
    }

    @Override
    public String describe() {
        return "Sculpture: " + title + ", carved from stone";
    }
}