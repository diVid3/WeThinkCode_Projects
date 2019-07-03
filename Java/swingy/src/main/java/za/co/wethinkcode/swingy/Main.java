package za.co.wethinkcode.swingy;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class Main {

  private static EntityManagerFactory ENTITY_MANAGER_FACTORY = Persistence.createEntityManagerFactory("swingy");

  public static void main( String[] args ) {

    ENTITY_MANAGER_FACTORY.close();
  }
}
